#include <bits/stdc++.h>
using namespace std;
int n,i,a[200200];
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<2*n; i++) scanf("%d",&a[i]);
  sort(a,a+2*n);
  r=1LL*(a[n-1]-a[0])*(a[2*n-1]-a[n]);
  for (i=n; i<2*n; i++) r=min(r,1LL*(a[i]-a[i-n+1])*(a[2*n-1]-a[0]));
  printf("%I64d\n",r);
  return 0;
}