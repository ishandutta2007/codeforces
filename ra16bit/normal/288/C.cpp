#include <stdio.h>
int n,m,x,y,l,i,k,a[1000100];
long long r;
int main() {
  scanf("%d",&n); m=n;
  for (k=20; k>=0; k--) {
    x=1<<k;
    if (n<x) continue;
	y=x*4-2;
	l=n-x+1;
    for (i=0; i<l; i++) {
	  a[x+i]=x-1-i;
	  a[x-1-i]=x+i;
	  r+=y;
	}
	n-=2*l;
  }
  printf("%I64d\n",r);
  for (i=0; i<=m; i++) printf("%d%c",a[i],(i==m)?'\n':' ');
  return 0;
}