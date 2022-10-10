#include <stdio.h>
int c=1000000,p,i,a,b,r;
int main() {
  for (i=0; i<4; i++) {
    scanf("%d",&p);
    if (p<c) c=p;
  }
  scanf("%d%d",&a,&b);
  if (c>a) {
    if (c<=b) r=c-a; else r=b-a+1;
  } else r=0;
  printf("%d\n",r);
  return 0;
}