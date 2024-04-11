#include <bits/stdc++.h>
using namespace std;
int t,xa,ya,xb,yb,dx,dy;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    dx=abs(xa-xb);
    dy=abs(ya-yb);
    if (dx==0 || dy==0) printf("%d\n",dx+dy); else printf("%d\n",dx+dy+2);
  }
  return 0;
}