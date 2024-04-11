#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,i,mx,a[MX],c[2];
long long s;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    s=c[0]=c[1]=mx=0;
    for (i=1; i<n-1; i++) {
      s+=a[i];
      ++c[a[i]&1];
      mx=max(mx,a[i]);
    }
    if (c[1]>0 && (mx==1 || n==3)) { puts("-1"); continue; }
    printf("%lld\n",(s+c[1])/2);
  }
  return 0;
}