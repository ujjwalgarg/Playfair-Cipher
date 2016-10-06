/**
* ujjwalgarg
* hand written and working
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

char matrix[5][5];

void printMatrix() {
    int i,j;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }
}

void createMatrix(char k[]) {
    int i=0,j=0,len,x=-1;
    int last_i,last_j,abc,xy,yz;
    len=strlen(k);
    int kount[30]={0};
    kount[9]=1;
    while(len--) {
        x++;
        if(j<=4) {
            if(kount[k[x]-97]==0) {
                matrix[i][j]=k[x];
                last_i=i;
                last_j=j;
                j++;
                kount[k[x]-97]++;
            }
        }
        else {
            j=0;
            i++;
            if(kount[k[x]-97]==0) {
                matrix[i][j]=k[x];
                last_i=i;
                last_j=j;
                j++;
                kount[k[x]-97]++;
            }
        }
    }
    if(last_j>=4) {
        last_i++;
        last_j=0;
    }
    else {
        last_j++;
    }
    for(abc=0;abc<26;abc++) {
        if(kount[abc]==0) {
            if(last_j<=4) {
                matrix[last_i][last_j]=abc+97;
                last_j++;
            }
            else  {
                last_j=0;
                last_i++;
                matrix[last_i][last_j]=abc+97;
                last_j++;
            }
        }
    }
    //printMatrix();
}

int findRow(char c) {
    int i,j;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            if(matrix[i][j]==c)
                return i;
        }
    }
    return 0;
}

int findCol(char c) {
    int i,j;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            if(matrix[i][j]==c)
                return j;
        }
    }
    return 0;
}

void cipher(char t[]) {
    int l,i,pos_x_row,pos_x_col,pos_y_row,pos_y_col,col_diff;
    char x,y;
    l=strlen(t);
    //printf("%s\n",t);
    for(i=0;i<l;i+=2) {
        x=t[i];
        y=t[i+1];
        pos_x_row=findRow(x);
        pos_x_col=findCol(x);
        pos_y_row=findRow(y);
        pos_y_col=findCol(y);
        if(pos_x_row!=pos_y_row && pos_x_col!=pos_y_col) {
            col_diff=abs(pos_x_col-pos_y_col);
            if(pos_x_col<pos_y_col) {
                pos_x_col+=col_diff;
                pos_y_col-=col_diff;
            }
            else {
                pos_x_col-=col_diff;
                pos_y_col+=col_diff;
            }
            printf("%c%c ",matrix[pos_x_row][pos_x_col],matrix[pos_y_row][pos_y_col]);
        }
        else if(pos_x_row==pos_y_row) {
            pos_x_col++;
            pos_x_col%=5;
            pos_y_col++;
            pos_y_col%=5;
            printf("%c%c ",matrix[pos_x_row][pos_x_col],matrix[pos_y_row][pos_y_col]);
        }
        else {
            pos_x_row++;
            pos_x_row%=5;
            pos_y_row++;
            pos_y_row%=5;
            printf("%c%c ",matrix[pos_x_row][pos_x_col],matrix[pos_y_row][pos_y_col]);
        }
    }
}

int main() {
    char key[10],text[100],pass[100];
    printf("Enter the Key\n");
    scanf("%s",key);
    createMatrix(key);
    fflush(stdin);
    printf("Enter the Text\n");
    gets(text);
    int l,i,x=0;
    l=strlen(text);
    for(i=0;i<l;i++) {
        if(text[i]!=' ') {
            pass[x]=text[i];
            x++;
        }
    }
    if(x%2==0) {
        pass[x]=(char)0;
    }
    else {
        pass[x]='x';
        x++;
        pass[x]=(char)0;
    }
    //puts(pass);
    cipher(pass);
    return 0;
}
