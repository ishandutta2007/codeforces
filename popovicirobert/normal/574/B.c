#include <stdio.h>
#include <stdlib.h>
int mat[4002][4002],v[4002];
int main(){
   // FILE*fi,*fout;
    int i,j,x,min,con,n,m,y;
   // fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    scanf("%d%d" ,&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d" ,&x,&y);
        mat[x][y]=mat[y][x]=1;
    }
    for(i=1;i<=n;i++){
        con=0;
        for(j=1;j<=n;j++)
            con+=mat[i][j];
        v[i]=con;
    }
    min=1000000000;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j&&mat[i][j]==1)
                for(x=1;x<=n;x++)
                    if(j!=i&&mat[j][x]==1&&mat[x][i]==1)
                        if(min>v[i]+v[j]+v[x]-6)
                           min=v[i]+v[j]+v[x]-6;
    if(min==1000000000)
        min=-1;
    printf("%d" ,min);
   // fclose(fi);
   // fclose(fout);
    return 0;
}