#include <stdio.h>
int n,i,k,a[100100];
int main() {
  scanf("%d",&n);
  if (n%4>1) { puts("-1"); return 0; }
  for (i=k=0; k+4<=n; i+=2, k+=4) {
    a[i+1]=i+2;
	a[i+2]=n-i;
	a[n-i]=n-i-1;
	a[n-i-1]=i+1;
  }
  if (k+1==n) a[i+1]=i+1;
  for (i=1; i<=n; i++) printf("%d%c",a[i],i==n?'\n':' ');
  return 0;
}