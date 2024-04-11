#include <stdio.h>
int a,b,c,n,i;
int gcd(int a, int b) { return (b==0)?a:gcd(b,a%b); }
int main() {
  scanf("%d%d%d",&a,&b,&n);
  for (i=0; n>0; i++) {
    if (i&1) c=gcd(b,n); else c=gcd(a,n);
    if (n<c) break; else n-=c;
  }
  printf("%d\n",1-(i&1));
  return 0;
}