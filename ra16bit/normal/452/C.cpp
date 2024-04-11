#include <stdio.h>
int n,m,k,i;
long double p,r;
int main() {
  scanf("%d%d",&n,&m);
  for (k=1; k<=n && k<=m; k++) {
    p=k/double(n);
    for (i=1; i<k; i++) {
      p*=m-i;
      p/=i;
    }
    for (i=1; i<=n-k; i++) {
      p*=m*n-m-i+1.;
      p/=i;
    }
    for (i=1; i<n; i++) {
      p/=m*n-i;
      p*=i;
    }
    r+=p;
  }
  printf("%.11lf\n",double(r));
  return 0;
}