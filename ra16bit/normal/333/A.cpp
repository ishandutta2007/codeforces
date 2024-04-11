#include <stdio.h>
long long n,i;
int main() {
  scanf("%I64d",&n);
  for (i=1; n%i==0; i*=3);
  printf("%I64d\n",(n+i-1)/i);
  return 0;
}