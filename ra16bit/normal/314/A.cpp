#include <stdio.h>
int n,k,p,a,i,m;
unsigned long long c,d,s;
int main() {
  scanf("%d%d",&n,&k);
  if (k<0) {
    p=-k;
	k=0;
  }
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
	c=n-i;
	c*=a;
	c*=i-m-1;
	if (s+p>=c+k) {
	  if (i>m+1) {
	    d=i-m-1;
	    d*=a;
	    s+=d;
	  }
	} else {
	  printf("%d\n",i);
	  m++;
	}
  }
  return 0;
}