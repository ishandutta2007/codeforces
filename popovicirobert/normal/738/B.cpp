#include <cstdio>
#define MAXN 1000
int mat[MAXN+1][MAXN+1];
int spl[MAXN+1][MAXN+1],spc[MAXN+1][MAXN+1];
int main(){
   FILE*fi,*fout;
   int n,m,i,j,p,ans;
  // fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&m) ;
   ans=0;
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
      fscanf(fi,"%d" ,&mat[i][j]);
      spl[i][j]=spl[i][j-1]+mat[i][j];
      spc[i][j]=spc[i-1][j]+mat[i][j];
    }
   for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
    if(mat[i][j]==0){
       if(spl[i][j]>0)
         ans++;
       if(spl[i][m]!=spl[i][j])
         ans++;
       if(spc[i][j]>0)
         ans++;
       if(spc[n][j]>spc[i][j])
         ans++;
    }
   fprintf(fout,"%d" ,ans);
 //  fclose(fi);
  // fclose(fout);
   return 0;
}