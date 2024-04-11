#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
const int MD[2]={1000000021,999999677};
const int H[2]={300187,300119};
int n,m,i,j,d,e,x,y,k[MX],a[2][MX],b[MX],cnt[MX],cc,ins[MX],u[MX],tot=1;
vector<int> g[MX],z[MX];
bool eq(int i, int j) {
  return g[i].size()==g[j].size() && a[0][i]==a[0][j] && a[1][i]==a[1][j];
}
bool cmp(int i, int j) {
  if (g[i].size()!=g[j].size()) return g[i].size()<g[j].size();
  if (a[0][i]!=a[0][j]) return a[0][i]<a[0][j];
  return a[1][i]<a[1][j];
}
long long sqr(long long x) { return x*x; }
void dfs(int i) {
  u[i]=tot;
  for (int j=0; j<z[i].size(); j++) if (u[z[i][j]]==0) {
    tot++;
    dfs(z[i][j]);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=0; i<n; i++) {
    g[i].push_back(i);
    sort(g[i].begin(),g[i].end());
    for (d=0; d<2; d++) for (j=0; j<g[i].size(); j++) a[d][i]=(1LL*a[d][i]*H[d]+g[i][j])%MD[d];
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (i=0; i<n; i=j, cc++) for (j=i; j<n && eq(k[i],k[j]); j++) {
    b[k[j]]=cc;
    cnt[cc]++;
  }
  for (i=0; i<n; i++) for (j=0; j<g[i].size(); j++) {
    x=g[i][j];
    y=b[i];
    if (y==b[x]) ins[y]++; else {
      for (e=0; e<z[y].size(); e++) if (z[y][e]==b[x]) break;
      if (e>=z[y].size()) {
        z[y].push_back(b[x]);
        if (z[y].size()>2) { puts("NO"); return 0; }
      }
    }
  }
  for (i=0; i<cc; i++) if (ins[i]!=sqr(cnt[i])) { puts("NO"); return 0; }
  for (i=0; i<cc; i++) if (z[i].size()<2 && u[i]==0) {
    dfs(i);
    tot+=5;
  }
  for (i=0; i<cc; i++) if (u[i]==0) { puts("NO"); return 0; }
  puts("YES");
  for (i=0; i<n; i++) printf("%d ",u[b[i]]);
  return 0;
}