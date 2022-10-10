#include <bits/stdc++.h>
using namespace std;
int t,n,i,a[400400];
long long r;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    r=a[0]=a[n+1]=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      r+=abs(a[i]-a[i-1]);
    }
    r+=a[n];
    for (i=1; i<=n; i++) if (a[i]>a[i-1] && a[i]>a[i+1]) r-=a[i]-max(a[i-1],a[i+1]);
    printf("%lld\n",r);
  }
  return 0;
}