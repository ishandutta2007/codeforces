#include <stdio.h>
const int md=1000000007;
int i,a,b,r;
long long x,y;
int main() {
  scanf("%d%d",&a,&b);
  x=a; y=a+1;
  if (a&1) y/=2; else x/=2;
  x=(x*y)%md;
  for (i=1; i<b; i++) r=(r+((x*b+a)%md)*i)%md;
  printf("%d\n",r);
  return 0;
}