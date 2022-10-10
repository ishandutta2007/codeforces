#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,m,q,i,j,l,x,p,o[MX],a[MX],f[MX][19],r[MX];
vector<int> v[MX];
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=1; i<=n; i++) {
    scanf("%d",&p);
    o[p]=i;
  }
  for (i=1; i<=m; i++) {
    scanf("%d",&a[i]);
    v[o[a[i]]].push_back(i);
    f[i][0]=i;
    for (j=0; ; j++) {
      x=(1<<j);
      if (x>n) break;
      p=o[a[i]]-x;
      if (p<=0) p+=n;
      auto it=lower_bound(v[p].begin(),v[p].end(),f[i][j]);
      if (!v[p].empty() && it!=v[p].begin()) {
        it--;
        f[i][j+1]=f[*it][j];
      }
      if (f[i][j+1]==0) break;
    }
    p=o[a[i]];
    r[i]=i;
    for (j=17; j>=0 && r[i]>0; j--) if ((n>>j)&1) {
      r[i]=f[r[i]][j];
      p-=(1<<j);
      if (p<=0) p+=n;
      if (p==o[a[i]]) break;
      auto it=lower_bound(v[p].begin(),v[p].end(),r[i]);
      if (!v[p].empty() && it!=v[p].begin()) {
        it--;
        r[i]=*it;
      } else r[i]=0;
    }
    //for (j=0; j<4; j++) printf("%d ",f[i][j]); puts(" F");
    //printf("%d R\n",r[i]);
    r[i]=max(r[i],r[i-1]);
  }
  while (q--) {
    scanf("%d%d",&l,&x);
    printf("%d",r[x]>=l);
  }
  return 0;
}