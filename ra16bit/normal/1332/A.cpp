#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,d,x,y,xl,yl,xr,yr;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y,&xl,&yl,&xr,&yr);
    if (a+b>=1 && xl==xr) { puts("No"); continue; }
    if (c+d>=1 && yl==yr) { puts("No"); continue; }
    b-=a;
    d-=c;
    puts((x+b>=xl && x+b<=xr && y+d>=yl && y+d<=yr)?"Yes":"No");
  }
  return 0;
}