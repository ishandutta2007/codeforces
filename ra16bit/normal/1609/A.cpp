#include <bits/stdc++.h>
using namespace std;
int t,n,i,mx;
long long m,s,a[22];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    m=1;
    for (mx=i=0; i<n; i++) {
      scanf("%lld",&a[i]);
      while (a[i]%2==0) {
        a[i]/=2;
        m*=2;
      }
      if (a[i]>a[mx]) mx=i;
    }
    a[mx]*=m;
    for (s=i=0; i<n; i++) s+=a[i];
    printf("%lld\n",s);
  }
  return 0;
}