#include <bits/stdc++.h>
using namespace std;
const int MX=300200;
int n,m,q,i,j,x,y,a[MX],w[MX],z[MX],c[MX];
long long s[MX],r[MX];
vector<int> g[MX],l[MX];
void dfs(int i, int p, int d) {
  a[d]=i; w[i]=d;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p || w[k]>=d) continue;
    if (w[k]) {
      int mx=i,mn=i;
      for (int e=w[k]; e<=d; e++) {
        mn=min(mn,a[e]);
        mx=max(mx,a[e]);
      }
      c[mx]=max(c[mx],mn);
    } else dfs(k,i,d+1);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (w[i]==0) dfs(i,0,1);
  s[1]=1;
  for (i=2; i<=n; i++) {
    c[i]=max(c[i],c[i-1]);
    s[i]=s[i-1]+i-c[i];
  }
  scanf("%d",&q);
  for (i=1; i<=q; i++) {
    scanf("%d%d",&x,&z[i]);
    l[x].push_back(i);
  }
  for (i=1; i<=n; i++) if (l[i].size()) {
    x=lower_bound(c+1,c+n+1,i)-c;
    for (j=0; j<l[i].size(); j++) {
      y=l[i][j];
      if (x<=z[y]) r[y]=s[z[y]]-s[x-1]+(x-i)*(x-i+1LL)/2; else r[y]=(z[y]-i+1LL)*(z[y]-i+2LL)/2;
    }
  }
  for (i=1; i<=q; i++) printf("%lld\n",r[i]);
  return 0;
}