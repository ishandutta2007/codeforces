#include <stdio.h>
int n,m,i;
char z;
int main() {
  scanf("%d%d",&n,&m);
  if (m>n) { puts("-1"); return 0; }
  if (m==1) {
    if (n==1) puts("a"); else puts("-1");
	return 0;
  }
  for (i=0; i<n; i++) {
    if (n-i==m-2) break;
	putchar((i&1)?'b':'a');
  }
  for (z='c'; i<n; i++, z++) putchar(z);
  putchar('\n');
  return 0;
}