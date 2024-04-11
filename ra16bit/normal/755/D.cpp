#include <stdio.h>
int n,m,i,j,x,y,s[1000100];
long long r;
int fs(int x) {
  int r=0;
  for (; x>0; x&=x-1) r+=s[x];
  return r;
}
int main() {
  scanf("%d%d",&n,&m);
  if (m*2>n) m=n-m;
  for (r=x=1, i=0; i<n; i++) {
    y=x+m;
    if (y>n) y-=n;
    for (j=x; j<=n; j=(j<<1)-(j&(j-1))) s[j]++;
    for (j=y; j<=n; j=(j<<1)-(j&(j-1))) s[j]++;
    if (x<y) r+=fs(y-1)-fs(x)+1; else r+=fs(n)-fs(x)+fs(y-1)+1;
    printf("%lld ",r);
    x=y;
  }
  return 0;
}