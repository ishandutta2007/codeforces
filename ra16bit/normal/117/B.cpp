#include <stdio.h>
int i,x,y,z;
int main() {
  scanf("%d%d%d",&x,&y,&z);
  for (i=1; i<z && i<=x; i++) if ((z-(i*1000000000LL)%z)%z>y) { printf("1 %09d\n",i); return 0; }
  puts("2");
  return 0;
}