#include <cstdio>
#define MAXN 500
int mat[MAXN+1][MAXN+1];
int main(){
    int i,j,n,k,m;
    scanf("%d%d" ,&n,&k);
    m=1;
    for(i=1;i<=n;i++){
        for(j=1;j<k;j++){
           mat[i][j]=m;
           m++;
        }
    }
    int s=0;
    for(i=1;i<=n;i++){
        s+=m;
        for(j=k;j<=n;j++){
           mat[i][j]=m;
           m++;
        }
    }
    printf("%d\n" ,s);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
           printf("%d " ,mat[i][j]);
           printf("\n");
    }
    return 0;
}