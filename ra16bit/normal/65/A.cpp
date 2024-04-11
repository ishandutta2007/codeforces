#include <stdio.h>
int a,b,c,d,e,f;
int main() {
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  if (d==0) { puts("Hermione"); return 0; }
  if (c==0) { puts("Ron"); return 0; }
  if (b==0) { puts("Hermione"); return 0; }
  if (a==0) { puts("Ron"); return 0; }
  if (f==0) { puts("Hermione"); return 0; }
  if (e==0) { puts("Ron"); return 0; }
  if (b*d*f>a*c*e) puts("Ron"); else puts("Hermione");
  return 0;
}