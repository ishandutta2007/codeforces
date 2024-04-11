#include <bits/stdc++.h>
using namespace std;
int t,n,a[100100];
long long i,cur,r;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (r=cur=i=0; i<n; i++) {
      r+=cur-a[i]*i;
      if (a[i]>0) r+=a[i]-a[i-1];
      cur+=a[i];
    }
    printf("%lld\n",r);
  }
  return 0;
}