#include <stdio.h>
int n,d,i,j,a[100100];
long long r;
int main() {
  scanf("%d%d",&n,&d);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    for (; j<n && a[j]-a[i]<=d; j++);
    r+=((j-i-1LL)*(j-i-2LL))/2;
  }
  printf("%I64d\n",r);
  return 0;
}