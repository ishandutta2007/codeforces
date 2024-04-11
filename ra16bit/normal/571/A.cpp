#include <cstdio>
#include <algorithm>
using namespace std;
int a[3],l,s,i,j,x;
long long r;
int main() {
  scanf("%d%d%d%d",&a[0],&a[1],&a[2],&l);
  s=a[0]+a[1]+a[2];
  for (i=0; i<=l; i++) r+=((i+1LL)*(i+2LL))/2;
  for (i=0; i<3; i++) for (j=0; j<=l; j++) {
    x=min(l-j,a[i]+j-(s-a[i]));
    if (x>=0) r-=((x+1LL)*(x+2LL))/2;
  }
  printf("%I64d\n",r);
  return 0;
}