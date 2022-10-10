#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,m,mn,mx,i,r,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (r=i=0; i<n; i++) scanf("%d",&a[i]);
    mn=mx=a[0];
    for (i=1; i<n; i++) {
      mn=min(mn,a[i]);
      mx=max(mx,a[i]);
      if (mx-mn>2*m) {
        mn=mx=a[i];
        ++r;
      }
    }
    printf("%d\n",r);
  }
  return 0;
}