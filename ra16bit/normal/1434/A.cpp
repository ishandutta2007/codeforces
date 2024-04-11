#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,tot,i,j,a[11],b[MX],cnt[MX],k[MX*6];
long long c[MX*6],cur,r;
bool cmp(int i, int j) { return c[i]<c[j]; }
int main() {
  for (i=0; i<6; i++) scanf("%d",&a[i]);
  sort(a,a+6);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&b[i]);
    for (j=0; j<6; j++) {
      k[m]=m;
      c[m++]=b[i]-a[j];
    }
  }
  sort(k,k+m,cmp);
  for (tot=i=j=0; i<m; i++) {
    for (; j<m && tot<n; j++) if (++cnt[k[j]/6]==1) ++tot;
    if (tot==n) {
      cur=c[k[j-1]]-c[k[i]];
      if (i) r=min(r,cur); else r=cur;
    }
    if (--cnt[k[i]/6]==0) --tot;
  }
  printf("%lld\n",r);
  return 0;
}