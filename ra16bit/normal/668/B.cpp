#include <stdio.h>
int n,q,i,t,x,a,b=1,r[1000100];
int main() {
  scanf("%d%d",&n,&q);
  while (q--) {
    scanf("%d",&t);
    if (t==1) {
      scanf("%d",&x);
      a=(a+n+x)%n;
      b=(b+n+x)%n;
    } else {
      a^=1;
      b^=1;
    }
  }
  for (i=0; i<n; i++) r[(((i&1)?b:a)+i-(i&1))%n]=i;
  for (i=0; i<n; i++) printf("%d ",r[i]+1);
  return 0;
}