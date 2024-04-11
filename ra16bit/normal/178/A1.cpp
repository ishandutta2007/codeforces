#include <stdio.h>
int n,i,j,a[100100];
long long r;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<n; i++) {
    for (j=0; i+(1<<j)<=n; j++);
    a[i+(1<<(j-1))]+=a[i];
    r+=a[i];
    printf("%I64d\n",r);
  }
  return 0;
}