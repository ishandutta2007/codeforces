#include <bits/stdc++.h>
#define MAXN 100
int mat[MAXN + 1][MAXN + 1];
int lin[MAXN + 1];
int col[MAXN + 1];
int main(){
   FILE*fi,*fout;
   int i,n,m,min,ans,j;
   //fi=fopen("C.in" ,"r");
   //fout=fopen("C.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d" ,&n,&m);
   for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
       fscanf(fi,"%d" ,&mat[i][j]);
   ans = 0;
   if(n < m) {
       for(i=1;i<=n;i++){
         int min=501;
         for(j=1;j<=m;j++)
           min=std::min(min, mat[i][j]);
         ans+=min;
         lin[i]+=min;
       }
       for(i=1;i<=m;i++){
         int min=501;
         for(j=1;j<=n;j++)
           min=std::min(min, mat[j][i]-lin[j]);
         ans+=min;
         col[i]+=min;
       }
   }
   else {
       for(i=1;i<=m;i++){
         int min=501;
         for(j=1;j<=n;j++)
           min=std::min(min, mat[j][i]);
         ans+=min;
         col[i]+=min;
       }
       for(i=1;i<=n;i++){
         int min=501;
         for(j=1;j<=m;j++)
           min=std::min(min, mat[i][j] - col[j]);
         ans+=min;
         lin[i]+=min;
       }
   }
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     if(lin[i]+col[j]!=mat[i][j]){
       fprintf(fout,"-1");
       return 0;
     }
   fprintf(fout,"%d\n" ,ans);
   for(i=1;i<=n;i++)
     while(lin[i]>0){
        lin[i]--;
        fprintf(fout,"row %d\n" ,i);
     }
    for(i=1;i<=m;i++)
     while(col[i]>0){
        col[i]--;
        fprintf(fout,"col %d\n" ,i);
     }
  // fclose(fi);
  // fclose(fout);
   return 0;
}