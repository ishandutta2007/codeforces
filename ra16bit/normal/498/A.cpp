#include <stdio.h>
int xa,ya,xb,yb,n,a,b,c,i,r;
long long za,zb;
int main() {
  scanf("%d%d%d%d%d",&xa,&ya,&xb,&yb,&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&a,&b,&c);
    za=1LL*a*xa+1LL*b*ya+c;
    zb=1LL*a*xb+1LL*b*yb+c;
    if ((za<0 && zb>0) || (za>0 && zb<0)) r++;
  }
  printf("%d\n",r);
  return 0;
}