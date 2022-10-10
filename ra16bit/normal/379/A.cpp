#include <stdio.h>
int a,b,c,d,r;
int main() {
  scanf("%d%d",&a,&b);
  while (a>0) {
    r+=a;
    d=a+c;
    a=d/b;
    c=d%b;
  }
  printf("%d\n",r);
  return 0;
}