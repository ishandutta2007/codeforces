#include <stdio.h>
int n,m;
long long pw3(int n) {
  if (n==0) return 1%m;
  if (n&1) return (pw3(n-1)*3)%m;
  long long x=pw3(n/2);
  return (x*x)%m;
}
int main() {
  scanf("%d%d",&n,&m);
  printf("%d\n",(int(pw3(n))+m-1)%m);
  return 0;
}