#include <stdio.h>
int a,b,m,r,i,w[100100];
int main() {
  scanf("%d%d%d%d",&a,&b,&m,&r);
  for (i=1; ; i++) {
    r=(a*r+b)%m;
    if (w[r]>0) { printf("%d\n",i-w[r]); break; }
    w[r]=i;
  }
  return 0;
}