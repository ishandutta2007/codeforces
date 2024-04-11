#include <stdio.h>
int i,j,x,a,b,n;
int ab(int x) { return (x<0)?(-x):x; }
int main() {
  scanf("%d%d%d",&a,&b,&n);
  if (b==0) { puts("0"); return 0; }
  for (i=1000; i>=-1000; i--) {
    for (x=a, j=0; j<n; x*=i, j++) if (ab(x)>ab(b)) break;
    if (j==n && x==b) { printf("%d\n",i); return 0; }
  }
  puts("No solution");
  return 0;
}