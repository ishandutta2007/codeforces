#include <stdio.h>
int i,j,n,c,a[3003],f[5000000];
double r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
	for (j=0; j<i; j++) if (a[j]>a[i]) c++;
  }
  if (c>0) {
    f[1]=3;
    for (i=2; i<c; i++) f[i]=f[i-2]+4;
    r=f[c-1]+1;
  } else r=0;
  printf("%.6lf\n",r);
  return 0;
}