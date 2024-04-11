#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int t,n,i,x,y,cnt,r,a[MX],b[MX],sa[MX],sb[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    for (i=0; i<n; i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    for (i=0; i<n; i++) {
      sa[i+1]=sa[i]+a[i];
      sb[i+1]=sb[i]+b[i];
    }
    for (r=0; ; r++) {
      cnt=(n+r)/4;
      x=sa[n+r]-sa[cnt];
      y=sb[min(n,n+r-cnt)];
      if (x>=y) break;
      sa[n+r+1]=sa[n+r]+100;
    }
    printf("%d\n",r);
  }
  return 0;
}