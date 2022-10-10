#include <stdio.h>
const int md=1000000009;
int n,m,k,e;
long long x,res;
long long pw2(int x) {
  if (x==0) return 1LL;
  if (x%2==1) return (2*pw2(x-1))%md;
  long long z=pw2(x/2);
  return (z*z)%md;
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  e=n-n/k;
  if (e>=m) { printf("%d\n",m); return 0; }
  x=m-e;
  res=(pw2(x)+md-1)%md;
  res=(res*2LL*k)%md;
  res=(res+md-x*k)%md;
  printf("%d\n",int((res+m)%md));
  return 0;
}