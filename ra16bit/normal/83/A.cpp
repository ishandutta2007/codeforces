#include <stdio.h>
int n,i,a[100100];
long long j,r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i=j) {
    for (j=i; j<n; j++) if (a[i]!=a[j]) break;
    r+=((j-i)*(j-i+1));
  }
  printf("%I64d\n",r/2);
  return 0;
}