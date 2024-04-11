#include <stdio.h>
int n,r;
int main() {
  scanf("%d",&n);
  if (n!=3) {
    for (r=1; r*r+(r-1)*(r-1)<n; r++);
    printf("%d\n",r+r-1);
  } else puts("5");
  return 0;
}