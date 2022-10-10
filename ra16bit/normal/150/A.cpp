#include <stdio.h>
long long m,n,i,a[100100];
int k;
int main() {
  scanf("%I64d",&n); m=n;
  for (i=2; i*i<=n; i++) while (n%i==0) { n/=i; a[k++]=i; }
  if (n!=m && n>1) a[k++]=n;
  if (k==2) puts("2"); else printf("1\n%I64d\n",a[0]*a[1]);
  return 0;
}