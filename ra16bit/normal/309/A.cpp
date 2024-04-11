#include <stdio.h>
int n,l,t,x,i,j,a[2000200];
double r;
int main() {
  scanf("%d%d%d",&n,&l,&t);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
	a[n+i]=a[i]+l;
  }
  t*=2; x=t/l; t%=l;
  for (i=0; i<n; i++) {
    for (; j<2*n && a[j]-a[i]<=t; j++);
	r+=j-i-1;
  }
  printf("%.8lf\n",0.25*(r+double(x)*double(n)*(n-1.)));
  return 0;
}