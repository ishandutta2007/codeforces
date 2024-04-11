#include <stdio.h>
int n,m,q,i,j,e,x,y,cur,a[5050],r,inf=2000000000;
bool was[200000100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    was[a[i]]=true;
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&x); r=inf;
    for (i=1; i<=n; i++) for (j=1; j<=m && j<r; j++) {
      cur=x-a[i]*j;
      if (cur==0) r=j;
      if (cur<=0) break;
      for (e=1; j+e<=m && j+e<r; e++) {
        y=cur/e;
        if (was[y] && y*e==cur) r=j+e;
      }
    }
    printf("%d\n",(r==inf)?-1:r);
  }
  return 0;
}