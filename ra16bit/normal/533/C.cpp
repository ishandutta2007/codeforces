#include <cstdio>
#include <algorithm>
using namespace std;
int xa,ya,xb,yb,nxb,nyb;
int main() {
  scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
  while (xb>0 || yb>0) {
    nxb=xb-1;
    nyb=yb-1;
    if (xb==0) {
      if (xa>0) xa--;
      nxb++;
    } else if (yb==0) {
      if (ya>0) ya--;
      nyb++;
    } else if (xb-yb>xa-ya) {
      if (ya>0) ya--;
    } else if (xb-yb<xa-ya) {
      if (xa>0) xa--;
    }
    if (xa==nxb && ya==nyb) { puts("Polycarp"); return 0; }
    xb=nxb;
    yb=nyb;
  }
  puts("Vasiliy");
  return 0;
}