#include <stdio.h>
int md=1000000007;
long long n,r;
long long pw2(long long b) {
  if (b==0) return 1LL;
  if (b&1) return (pw2(b-1)*2)%md;
  long long x=pw2(b/2);
  return (x*x)%md;
}
int main() {
  scanf("%I64d",&n);
  if (n==0) { puts("1"); return 0; }
  r=pw2(n-1);
  printf("%I64d\n",(r*(r*2+1))%md);
  return 0;
}