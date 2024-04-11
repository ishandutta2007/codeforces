#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,k,x,i;
long long best,s[MX];
long long sum(long long x) {
  return (x*(x-1))/2;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    k=min(m,n);
    for (i=1; i<=n; i++) {
      scanf("%d",&x);
      s[i]=s[i-1]+x;
      if (i==k) best=s[i]; else if (i>k) best=max(best,s[i]-s[i-k]);
    }
    best+=sum(m);
    if (m>n) best-=sum(m-n);
    printf("%lld\n",best);
  }
  return 0;
}