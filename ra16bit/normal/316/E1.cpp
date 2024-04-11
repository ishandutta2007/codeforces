#include <stdio.h>
const int md=1000000000;
int a[200100],i,n,m,x,y,t,z,r;
long long f[200100];
int main() {
  f[0]=f[1]=1;
  for (i=2; i<200100; i++) f[i]=(f[i-1]+f[i-2])%md;
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&t,&x,&y);
	if (t==2) {
	  for (r=z=0; z<=y-x; z++) r=(r+f[z]*a[x+z])%md;
	  printf("%d\n",r);
	} else a[x]=y;
  }
  return 0;
}