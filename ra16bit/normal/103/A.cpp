#include <stdio.h>
int i,n;
long long a,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d",&a);
    r+=(a-1)*(i+1)+1;
  }
  printf("%I64d\n",r);
  return 0;
}