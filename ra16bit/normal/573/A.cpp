#include <stdio.h>
int n,x,y,i;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    while (x%2==0) x/=2;
    while (x%3==0) x/=3;
    if (i) {
      if (y!=x) { puts("No"); return 0; }
    } else y=x;
  }
  puts("Yes");
  return 0;
}