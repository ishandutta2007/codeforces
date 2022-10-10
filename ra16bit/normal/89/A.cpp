#include <stdio.h>
int i,n,m,k,a[10010];
long long d;
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  if (n%2==0) { puts("0"); return 0; }
  if (n==1) {
    d=m; d*=k;
    if (a[0]<d) d=a[0];
    printf("%I64d\n",d);
    return 0;
  }
  d=m/((n+1)/2); d*=k;
  for (i=0; i<n; i+=2) if (a[i]<d) d=a[i];
  printf("%I64d\n",d);
  return 0;
}