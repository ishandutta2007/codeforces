#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,m,q,r,i,j,mx,s,rgh,a[MX],k[MX],le[MX],ri[MX],cnt[MX],w[MX];
bool cmp(int i, int j) { return le[i]<le[j]; }
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    if (w[a[i]]==0) {
      k[m]=m;
      le[m]=i;
      cnt[m]=0;
      w[a[i]]=++m;
    }
    ri[w[a[i]]-1]=i;
    cnt[w[a[i]]-1]++;
  }
  sort(k,k+m,cmp);
  for (i=0; i<m; i=j) {
    rgh=ri[k[i]];
    s=mx=cnt[k[i]];
    for (j=i+1; j<m; j++) {
      if (le[k[j]]>rgh) break;
      rgh=max(rgh,ri[k[j]]);
      mx=max(mx,cnt[k[j]]);
      s+=cnt[k[j]];
    }
    r+=s-mx;
  }
  printf("%d\n",r);
  return 0;
}