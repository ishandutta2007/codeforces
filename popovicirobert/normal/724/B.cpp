#include <cstdio>
#include <cstring>
int mat[21][21],v[21][21],vf[21][21];
int main(){
    int i,j,n,m,c1,c2,flag,flag1,x,poz,aux,con;
    scanf("%d%d" ,&n,&m);
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
      scanf("%d" ,&mat[i][j]);
    flag=0;
    for(c1=1;c1<=m;c1++)
      for(c2=c1;c2<=m;c2++){
         for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
            v[i][j]=mat[i][j];
         for(i=1;i<=n;i++){
            aux=v[i][c1];
            v[i][c1]=v[i][c2];
            v[i][c2]=aux;
         }
         memset(vf,0,sizeof(vf));
         flag1=1;
         for(i=1;i<=n;i++){
            con=0;
            for(j=1;j<=m;j++)
             if(vf[i][j]==0){
                 poz=j;
                 x=0;
                 while(vf[i][poz]==0){
                    vf[i][poz]=1;
                    poz=v[i][poz];
                    x++;
                 }
                 con+=x-1;
             }
            if(con>1)
                flag1=0;
         }
         if(flag1==1)
              flag=1;
      }
    if(flag==1)
          printf("YES");
    else
          printf("NO");
    return 0;
}