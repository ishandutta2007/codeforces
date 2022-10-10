#include <stdio.h>
int a,b;
long long c,d,x,y,o;
int main() {
  scanf("%d%d",&a,&b);
  o=0; x=a; y=b;
  while (x!=y) if (x<y) {
    c+=x-o; o=x; x+=a;
  } else {
    d+=y-o; o=y; y+=b;
  }
  if (a>b) c+=x-o; else d+=y-o;
  if (c==d) puts("Equal"); else if (c>d) puts("Dasha"); else puts("Masha");
  return 0;
}