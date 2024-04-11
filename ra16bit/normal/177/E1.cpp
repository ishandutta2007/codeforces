#include <stdio.h>
int n,c,i,a[10010],b[10010];
long long solve(int c) {
  long long l=1,r=2000000000000000000LL,h,cur;
  long double db;
  int i;
  while (l<r) {
    h=(l+r)/2;
    for (i=cur=0; i<n; i++) {
      db=((((long double)h)/((long double)b[i]))*a[i]);
      if (db>c+10) break;
      cur+=int(db)+1;
    }
    if (i>=n && cur<c) l=h+1; else r=h;
  }
  return r;
}
int main() {
  scanf("%d%d",&n,&c);
  for (i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
  printf("%I64d\n",solve(c+1)-solve(c));
  return 0;
}