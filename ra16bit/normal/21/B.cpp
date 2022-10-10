#include <stdio.h>
int a1,b1,c1,a2,b2,c2;
int main() {
  scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
  if (a1==0 && b1==0 && c1!=0) { puts("0"); return 0; }
  if (a2==0 && b2==0 && c2!=0) { puts("0"); return 0; }
  if (a1==0 && b1==0 && c1==0) { puts("-1"); return 0; }
  if (a2==0 && b2==0 && c2==0) { puts("-1"); return 0; }
  if (a1*b2==b1*a2) {
    if (a1*c2==c1*a2) puts("-1"); else puts("0");
  } else puts("1");
  return 0;
}