#include <stdio.h>
int t,n;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    if (n<3) puts("0"); else printf("%d\n",n-2);
  }
  return 0;
}