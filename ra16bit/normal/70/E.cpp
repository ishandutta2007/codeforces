#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,ks,i,j,v,k,x,y,cur,last,d[188],s[188],rs[188],fi,fr,q[188],ll[188];
long long f[188][188][2],g[188][188][2],r,inf=10000000;
vector <int> z[188];
void dfs(int i, int p) {
  int j;
  for (j=0; j<z[i].size(); j++) if (z[i][j]!=p) dfs(z[i][j],i);
  for (last=j=0; j<z[i].size(); j++) {
    cur=z[i][j];
    if (cur==p) continue;
    for (v=0; v<n; v++) for (k=0; k<2; k++) if (g[last][v][k]<inf) {
      if (v>0) g[cur][v][k|1]=min(g[cur][v][k|1],g[last][v][k]+f[cur][v-1][1]);
      g[cur][v][k]=min(g[cur][v][k],g[last][v][k]+f[cur][v][1]);
      g[cur][v][k]=min(g[cur][v][k],g[last][v][k]+f[cur][v+1][0]);
    }
    last=cur;
  }
  ll[i]=last;
  f[i][0][0]=f[i][0][1]=min(g[last][0][1],g[last][0][0])+ks;
  for (v=1; v<n; v++) {
    f[i][v][0]=min(g[last][v][1],g[last][v][0])+d[v];
    f[i][v][1]=g[last][v][1]+d[v];
  }
}
void ans(int i, int v, int k, int p) {
  int j,cur,last;
  rs[i]=i;
  s[i]=2*n*int(v!=0);
  q[fr++]=i;
  if (z[i].size()==0) return;
  if (v==0 || k==0) k=int(g[ll[i]][v][1]<g[ll[i]][v][0]); else k=1;
  cur=-1;
  for (j=int(z[i].size())-1; j>=-1; j--) {
    if (j>=0) {
      last=z[i][j];
      if (last==p) continue;
    } else last=0;
    if (cur==-1) { cur=last; continue; }
    if (k==1 && v>0) {
      if (g[cur][v][k]==g[last][v][0]+f[cur][v-1][1]) { ans(cur,v-1,1,i); k=0; cur=last; continue; }
      if (g[cur][v][k]==g[last][v][1]+f[cur][v-1][1]) { ans(cur,v-1,1,i); cur=last; continue; }
    }
    if (g[cur][v][k]==g[last][v][k]+f[cur][v][1]) { ans(cur,v,1,i); cur=last; continue; }
    if (g[cur][v][k]==g[last][v][k]+f[cur][v+1][0]) { ans(cur,v+1,0,i); cur=last; continue; }
  }
}
int main() {
  scanf("%d%d",&n,&ks);
  for (i=1; i<n; i++) scanf("%d",&d[i]);
  for (i=n; i<188; i++) d[i]=1000000000;
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    z[x].push_back(y);
    z[y].push_back(x);
  }
  inf*=inf;
  for (i=0; i<=n; i++) for (j=0; j<=n; j++) for (k=0; k<2; k++) if (i>0 || k==1) g[i][j][k]=inf;
  dfs(1,0); r=inf;
  for (i=0; i<n; i++) r=min(r,f[1][i][1]);
  printf("%I64d\n",r);
  for (i=0; i<n; i++) if (r==f[1][i][1]) { ans(1,i,1,0); break; }
  while (fi<fr) {
    i=q[fi++];
    for (j=0; j<z[i].size(); j++) if (s[i]+1<s[z[i][j]]) {
      s[z[i][j]]=s[i]+1; rs[z[i][j]]=rs[i]; q[fr++]=z[i][j];
    }
  }
  for (i=1; i<=n; i++) printf("%d ",rs[i]);
  return 0;
}