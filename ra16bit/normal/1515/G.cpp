#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,m,num,q,i,j,x,y,z,a[MX],p[MX];
long long dst[MX],ins[MX],out[MX],v[MX];
vector<int> g[MX],f[MX],og[MX],of[MX];
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
void dfs(int i, long long d) {
  dst[i]=d;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (dst[k]==0) dfs(k,d+f[i][j]);
  }
  a[++num]=i;
}
void ofs(int i, int st, long long d) {
  p[i]=st;
  ins[i]=dst[i]-dst[st];
  out[i]=d;
  v[st]=gcd(v[st],ins[i]+out[i]);
  for (int j=0; j<og[i].size(); j++) {
    int k=og[i][j];
    if (p[k]==0) ofs(k,st,d+of[i][j]);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y);
    f[x].push_back(z);
    og[y].push_back(x);
    of[y].push_back(z);
  }
  for (i=1; i<=n; i++) if (dst[i]==0) dfs(i,1);
  for (i=num; i>0; i--) if (p[a[i]]==0) ofs(a[i],a[i],0);
  for (i=1; i<=n; i++) {
    y=p[i];
    for (j=0; j<g[i].size(); j++) {
      x=g[i][j];
      if (p[x]==y) v[y]=gcd(v[y],ins[i]+f[i][j]+out[x]);
    }
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d%d",&x,&y,&z);
    if (y==0 || gcd(z-y,z)%gcd(v[p[x]],z)==0) puts("YES"); else puts("NO");
  }
  return 0;
}