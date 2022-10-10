#include <stdio.h>
int n,m,x,i,q1,q2,a[2];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    a[x&1]++;
  }
  m=n-m;
  if (m==0) {
    if (a[1]&1) puts("Stannis"); else puts("Daenerys");
  } else if (m&1) {
    bool q=(a[0]<=m && (a[1]+a[0]-m)%2==0);
    if ((a[0]<=m/2 && q) || a[1]<=m/2 || (a[0]-1<=m/2 && q && a[1]-1<=m/2)) puts("Daenerys"); else puts("Stannis");
  } else if (a[0]<=m/2 && (a[1]+a[0]-m)%2==1) puts("Stannis"); else puts("Daenerys");
  return 0;
}