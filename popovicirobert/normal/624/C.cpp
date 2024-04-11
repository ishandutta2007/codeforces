#include <cstdio>
#include <algorithm>
int mat[501][501];
char v[501];
int main(){
   // FILE*fi,*fout;
    int i,j,n,m,x,y,flag,con,b,e;
 //   fi=fopen("sl.in" ,"r");
 //   fout=fopen("sl.out" ,"w");
    scanf("%d%d" ,&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d" ,&x,&y);
        mat[x][y]=mat[y][x]=1;
    }
    int flag1=1;
    for(i=1;i<=n&&flag1;i++){
        con=0;
        for(j=1;j<=n;j++)
           if(mat[i][j]==1)
              con++;
        if(con==n-1)
           b=e=2;
        else{
           b=1;
           e=3;
        }
        for(x=b;x<=e;x++){
            flag=1;
            for(j=1;j<i;j++){
               if(mat[i][j]==1){
                   if(v[j]=='a'&&x==3)
                      flag=0;
                   if(v[j]=='c'&&x==1)
                      flag=0;
               }
               else{
                   if(v[j]=='a'&&(x==2||x==1))
                       flag=0;
                   if(v[j]=='b')
                       flag=0;
                   if(v[j]=='c'&&(x==2||x==3))
                       flag=0;
               }
            }
            if(flag==1){
               if((x==2&&con==n-1)||x!=2)
                  v[i]='a'+x-1;
            }
        }
        if(v[i]<'a')
          flag1=0;
    }
    if(flag1==0)
        printf("No");
    else{
        printf("Yes\n");
        for(i=1;i<=n;i++)
            printf("%c" ,v[i]);
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}