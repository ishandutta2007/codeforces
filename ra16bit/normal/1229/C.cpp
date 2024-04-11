#include <bits/stdc++.h>
using namespace std;
int n,m,q,i,j,x,y,z,a[200200],w[100100];
long long ans,l[100100],r[100100];
vector<int> g[100100];
bool old[200200];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) a[i]=w[i]=i;
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
    if (x<y) {
      r[x]++; l[y]++;
    } else {
      l[x]++; r[y]++;
    }
  }
  for (i=1; i<=n; i++) {
    ans+=l[i]*r[i];
    sort(g[i].begin(),g[i].end());
  }
  printf("%I64d\n",ans);
  scanf("%d",&q);
  for (i=1; i<=q; i++) {
    scanf("%d",&x);
    if (g[x].size()<2*(n+i-w[x])) for (j=0; j<g[x].size(); j++) {
      y=g[x][j];
      if (w[y]>w[x]) {
        ans-=l[y]*r[y];
        l[y]--;
        r[y]++;
        ans+=l[y]*r[y];
      }
    } else for (j=w[x]+1; j<n+i; j++) if (!old[j]) {
      y=a[j];
      z=lower_bound(g[x].begin(),g[x].end(),y)-g[x].begin();
      if (z<g[x].size() && g[x][z]==y) {
        ans-=l[y]*r[y];
        l[y]--;
        r[y]++;
        ans+=l[y]*r[y];
      }
    }
    old[w[x]]=true;
    a[n+i]=x;
    w[x]=n+i;
    ans-=l[x]*r[x];
    l[x]=g[x].size();
    r[x]=0;
    printf("%I64d\n",ans);
  }
  return 0;
}