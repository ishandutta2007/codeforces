#include <stdio.h>
int n,k,i,j,a[10010];
int main() {
  scanf("%d%d",&n,&k);
  for (i=1; i<n; i++) a[i]=1;
  for (j=0; j<k; j++) {
    for (i=1; i<n; i++) if ((a[i]&(n-i))==0) {
	  printf("%d ",i);
	  a[i]*=2;
	} else if (n-i>a[i] && (((1<<(j+1))-1)&(n-i))==(a[i]+(1<<j))) {
	  printf("%d ",n-(1<<j));
	  a[i]+=1<<j;
	} else printf("%d ",n);
	printf("%d\n",n);
  }
  return 0;
}