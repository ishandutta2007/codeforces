#include <bits/stdc++.h>
std::vector <int> G[1001];
int f[1001];
int nr[1001];
int is[1001];
int viz[1001];
int viz1[1001];
int good[1001];
bool mat[1001][1001];
int cnt;
void DFS(int nod){
   viz[nod]=cnt;
   is[cnt]|=f[nod];
   nr[cnt]++;
   for(auto x:G[nod])
    if(viz[x]==0)
       DFS(x);
}
void DFS1(int nod){
   viz1[nod]=cnt;
   good[nod]|=is[cnt];
   for(auto x:G[nod])
    if(viz1[x]==0)
     DFS1(x);
}
int main(){
   FILE*fi,*fout;
   int i,n,m,k,x,y,max,ans,j,poz;
  // fi=fopen("C.in" ,"r");
  // fout=fopen("C.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d%d%d" ,&n,&m,&k);
   for(i=1;i<=k;i++){
     fscanf(fi,"%d" ,&x);
     f[x]=1;
   }
   for(i=1;i<=m;i++){
     fscanf(fi,"%d%d" ,&x,&y);
     G[x].push_back(y);
     G[y].push_back(x);
     mat[x][y]=mat[y][x]=1;
   }
   cnt=0;
   max=0;
   poz=-1;
   for(i=1;i<=n;i++)
    if(viz[i]==0){
       cnt++;
       DFS(i);
       if(is[cnt]==1&&max<nr[cnt]){
         max=nr[cnt];
         poz=cnt;
       }
       DFS1(i);
    }
  ans=0;
  for(i=1;i<=n;i++)
   for(j=i+1;j<=n;j++)
    if(mat[i][j]==0&&viz[i]==viz[j]){
     ans++;
     mat[i][j]=1;
    }
  for(i=1;i<=n;i++)
   for(j=i+1;j<=n;j++)
    if(mat[i][j]==0&&good[i]==0&&good[j]==0)
      ans++;
   //   printf("%d" ,good[1]);
  for(i=1;i<=n;i++)
   if(viz[i]==poz)
    for(j=1;j<=n;j++)
     if(mat[i][j]==0&&good[j]==0)
      ans++;
  fprintf(fout,"%d" ,ans);
  // fclose(fi);
 //  fclose(fout);
   return 0;
}