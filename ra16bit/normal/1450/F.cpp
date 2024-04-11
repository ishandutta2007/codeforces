#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,j,m,mx,r,a[MX],cnt[MX],was[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      cnt[i+1]=0;
      was[i+1]=0;
    }
    for (r=m=mx=i=0; i<n; i=j) {
      for (j=i+1; j<n && a[j]!=a[j-1]; j++);
      if (a[i]!=a[j-1]) {
        ++was[a[i]];
        ++was[a[j-1]];
        ++m;
      } else {
        ++cnt[a[i]];
        if (cnt[a[i]]>cnt[mx]) mx=a[i];
      }
      r++;
    }
    if (mx>0) {
      for (i=1; i<=n; i++) if (i!=mx) cnt[mx]-=cnt[i];
      cnt[mx]-=m+1-was[mx];
      for (i=1; i<n && cnt[mx]>0; i++) if (a[i]!=a[i-1] && a[i]!=mx && a[i-1]!=mx) {
        --cnt[mx];
        ++r;
      }
      if (cnt[mx]>0) puts("-1"); else printf("%d\n",r-1);
    } else printf("%d\n",r-1);
  }
  return 0;
}