#include <cstdio>
#include <vector> 
using namespace std;

int main() {
 int n,m;
 scanf("%d%d",&n,&m);
 bool g[n+1][n+1]; int st[n+1];
 for (int i=1;i<=n;i++)
 { st[i]=0;
  for (int j=1;j<=n;j++)
   g[i][j]=false;
 }
 for (int i=1;i<=m;i++)
 {
  int a,b; scanf("%d%d",&a,&b);
  g[a][b]=true; g[b][a]=true; st[a]++; st[b]++;
 }
 //for (int i=1;i<=n;i++)
 // st[i]/=2;
 int res=0;
 while (true) 
 {
   vector <int> d;
  for (int i=1;i<=n;i++)
   if (st[i]==1) d.push_back(i);
 // for (int i=1;i<=n;i++)
 //  printf("%d ",st[i]);puts("");
  if (d.empty()) break; else res++; 
  for (int k=0;k<(int)d.size();k++)
   {
     st[d[k]]=0;
     for (int i=1;i<=n;i++)
       {if (g[i][d[k]]) st[i]--; g[i][d[k]]=false; g[d[k]][i]=false; }
   }
 }
 printf("%d",res);
 return 0;
 }