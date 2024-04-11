#include <stdio.h>
int n,i,j,k,md=1000000007;
long long r;
long long pow(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pow(a,b-1)*a)%md;
  long long x=pow(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d",&n); r=1;
  for (i=1; i<=n; i++) r=(r*(n+i))%md;
  for (i=2; i<=n; i++) r=(r*pow(i,md-2))%md;
  r-=n;
  if (r<0) r+=md;
  printf("%I64d\n",r);
  return 0;
}