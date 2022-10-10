#include <stdio.h>
int n,i,f,md=1000003;
int main() {
  scanf("%d",&n); f=1;
  for (i=2; i<=n; i++) f=(f*3)%md;
  printf("%d\n",f);
  return 0;
}