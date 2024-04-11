#include <bits/stdc++.h>
using namespace std;
const int MX=1000100,md=1000000007;
int n,m,aa,b,r,i;
long long a[MX],f[MX],o[MX],c,cur;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d%d%d",&n,&m,&aa,&b);
  c=(1LL*n*m)%md;
  for (a[0]=f[0]=o[0]=i=1; i<MX; i++) {
    a[i]=(a[i-1]*c)%md;
    f[i]=(f[i-1]*i)%md;
    o[i]=pw(f[i],md-2);
  }
  for (i=0; i<n-1 && i<m; i++) {
    if (i<n-2) {
      cur=(a[n-i-3]*(i+2LL))%md;
      cur=(cur*m)%md;
    } else cur=1;
    cur=(cur*f[n-2])%md;
    cur=(cur*o[n-2-i])%md;
    cur=(cur*f[m-1])%md;
    cur=(cur*o[i])%md;
    r=(r+cur*o[m-1-i])%md;
  }
  printf("%d\n",r);
  return 0;
}