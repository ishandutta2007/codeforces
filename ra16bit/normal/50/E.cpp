#include <stdio.h>
#include <math.h>
const int mx=20000000;
int n,m,x,y,i,l[2*mx];
long long b,r;
double eps=1e-8;
int main() {
  scanf("%d%d",&n,&m);
  for (b=1; b<=n; b++) {
    if (b*b<=m) {
      x=0;
      r+=2*b*b-1;
    } else {
      x=int(sqrt(b*b-m)-eps)+1;
      r+=2*m;
    }
    y=int(sqrt(b*b-1)+eps);
    if (x==0) {
      r-=2*y+1;
      l[mx-b-y]++; l[mx-b+y+1]--;
    } else if (y>=x) {
      r-=2*(y-x+1);
      l[mx-b-y]++; l[mx-b-x+1]--;
      l[mx-b+x]++; l[mx-b+y+1]--;
    }
  }
  for (i=x=0; i<2*mx; i++) {
    x+=l[i];
    if (x>0) r++;
  }
  printf("%I64d\n",r);
  return 0;
}