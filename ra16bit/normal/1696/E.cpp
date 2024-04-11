#include <bits/stdc++.h>
using namespace std;
const int MX=200100,md=1000000007;
int n,i,j,le,ri,nle,nri,res,a[MX];
long long fc,cur;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d",&n);
  ++n;
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  while (a[n]==0 && n>0) --n;
  if (n==0) { puts("0"); return 0; }
  le=a[1];
  ri=a[1];
  cur=a[1];
  for (fc=i=1; i<=n; i++) {
    fc=(fc*i)%md;
    nri=a[i]+i-1;
    nle=nri-i+1;
    if (le>nri || nle>ri) {
      cur=1;
      le=nle;
      ri=nri;
      for (j=le; j<=ri; j++) cur=(cur*j)%md;
    } else {
      while (le>nle) { --le; cur=(cur*le)%md; }
      while (ri<nri) { ++ri; cur=(cur*ri)%md; }
      while (le<nle) { cur=(cur*pw(le,md-2))%md; ++le; }
      while (ri>nri) { cur=(cur*pw(ri,md-2))%md; --ri; }
    }
    res=(res+cur*pw(fc,md-2))%md;
  }
  printf("%d\n",res);
  return 0;
}