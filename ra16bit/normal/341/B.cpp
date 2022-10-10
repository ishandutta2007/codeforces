#include <stdio.h>
const int inf=1000000000;
int n,m=1,i,x,l,r,h,a[100100];
int main() {
  a[1]=inf;
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
	l=0; r=m;
	while (l<r) {
	  h=(l+r)/2;
	  if (a[h]>x) r=h; else l=h+1;
	}
	a[r]=x;
	if (r==m) a[++m]=inf;
  }
  printf("%d\n",m-1);
  return 0;
}