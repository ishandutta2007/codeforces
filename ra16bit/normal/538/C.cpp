#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,x,y,r,d[100100],h[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&d[i],&h[i]);
    if (i>0) {
      x=d[i]-d[i-1];
      y=abs(h[i]-h[i-1]);
      if (y>x) {
        puts("IMPOSSIBLE");
        return 0;
      }
      x-=y;
      r=max(r,max(h[i],h[i-1])+x/2);
    } else r=max(r,h[i]+d[i]-1);
  }
  r=max(r,h[m-1]+n-d[m-1]);
  printf("%d\n",r);
  return 0;
}