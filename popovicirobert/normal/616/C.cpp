#include <cstdio>
#define MAXN 1000
char mat[2][MAXN+2][MAXN+2];
int conex[MAXN+2][MAXN+2],sef[MAXN+2][MAXN+2],l,c,t,con,nr,con1;
void fill(){
    con++;
    mat[t][l][c]='!';
    sef[l][c]=nr;
    conex[l][c]=con1;
    if(mat[t][l-1][c]=='.'){
        l--;
        fill();
        l++;
    }
    if(mat[t][l+1][c]=='.'){
        l++;
        fill();
        l--;
    }
    if(mat[t][l][c-1]=='.'){
        c--;
        fill();
        c++;
    }
    if(mat[t][l][c+1]=='.'){
        c++;
        fill();
        c--;
    }

}
int main(){
    int n,m,i,j;
    char a;
    scanf("%d%d " ,&n,&m);
    a=fgetc(stdin);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            mat[0][i][j]=mat[1][i][j]=a;
            a=fgetc(stdin);
        }
        a=fgetc(stdin);
    }
    for(j=0;j<2;j++)
       for(i=0;i<=n+1;i++)
        mat[j][i][0]=mat[j][i][m+1]='*';
    for(j=0;j<2;j++)
       for(i=0;i<=m+1;i++)
        mat[j][0][i]=mat[j][n+1][i]='*';
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mat[0][i][j]=='.'){
                l=i;
                c=j;
                nr=i*10000+j;
                con1=con=t=0;
                fill();
                l=i;
                c=j;
                t=1;
                con1=con;
                fill();

            }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
           if(mat[0][i][j]=='*'){
               int x;
               x=conex[i-1][j];
               if(sef[i][j+1]!=sef[i-1][j])
                  x+=conex[i][j+1];
               if(sef[i+1][j]!=sef[i-1][j]&&sef[i+1][j]!=sef[i][j+1])
                  x+=conex[i+1][j];
               if(sef[i][j-1]!=sef[i-1][j]&&sef[i][j-1]!=sef[i][j+1]&&sef[i][j-1]!=sef[i+1][j])
                  x+=conex[i][j-1];
                x++;
               printf("%d" ,x%10);
           }
           else
              printf(".");
        printf("\n");
    }
    return 0;
}