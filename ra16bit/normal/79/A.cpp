#include <stdio.h>
int x,y,i,j;
int main() {
  scanf("%d%d",&x,&y);
  for (i=0; x*100+y*10>=220; i++) if (i&1) {
    for (j=0; j<=2; j++) if (x>=j && y>=22-j*10) { x-=j; y-=22-j*10; break; }
    if (j>2) break;
  } else {
    for (j=2; j>=0; j--) if (x>=j && y>=22-j*10) { x-=j; y-=22-j*10; break; }
    if (j<0) break;
  }
  if (i&1) puts("Ciel"); else puts("Hanako");
  return 0;
}