#include <stdio.h>
int a,b,c,d;
bool ok(int a, int b) {
  if (b<a-1) return false;
   return (b<=2*(a+1));
}
int main() {
  scanf("%d%d",&a,&b);
  scanf("%d%d",&c,&d);
  if (ok(a,d) || ok(b,c)) puts("YES"); else puts("NO");
  return 0;
}