#include <stdio.h>
int n,m,a,b,c,i;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; ; i++) {
    if (i%6==0) c++; else {
      if (i%2==0) a++; else if (i%3==0) b++;
    }
    if (a+c>=n && b+c>=m && a+b+c>=n+m) break;
  }
  printf("%d\n",i);
  return 0;
}