#include <stdio.h>
int n,m,t,a,x,k,c[200200];
double b[200200],s;
int main() {
  n=1; s=0;
  scanf("%d",&m);
  while (m--) {
    scanf("%d",&t);
	if (t==1) {
	  scanf("%d%d",&a,&x);
	  b[a]+=x;
	  s+=double(a)*x;
	} else if (t==2) {
	  scanf("%d",&k);
	  c[++n]=k;
	  b[n]=0;
	  s+=k;
	} else {
	  b[n-1]+=b[n];
	  s-=c[n];
	  s-=b[n--];
	}
    printf("%.8lf\n",s/n);
  }
  return 0;
}