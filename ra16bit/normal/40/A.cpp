#include <stdio.h>
int i,x,y,z;
int main() {
  scanf("%d%d",&x,&y); z=x*x+y*y;
  if (x==0 || y==0) { puts("black"); return 0; }
  for (i=1; ; i++) if (z<=i*i) {
    if (z==i*i) puts("black");
    else if (i&1) {
      if ((x>0 && y>0) || (x<0 && y<0)) puts("black"); else puts("white");
    } else {
      if ((x>0 && y>0) || (x<0 && y<0)) puts("white"); else puts("black");
    }
    break;
  }
  return 0;
}