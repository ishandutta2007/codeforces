#include <bits/stdc++.h>
using namespace std;
int t,x,y,xc,yc,i;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&x,&y);
    if (x>y) { puts("NO"); continue; }
    if (x==y) { puts("YES"); continue; }
    xc=yc=0;
    for (i=0; i<=30; i++) {
      if ((x>>i)&1) ++xc;
      if ((y>>i)&1) ++yc;
      if (xc<yc) break;
    }
    puts((i>30)?"YES":"NO");
  }
  return 0;
}