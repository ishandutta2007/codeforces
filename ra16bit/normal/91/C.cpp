#include <stdio.h>
int n,m,r,i,x,y,p[100100],md=1000000009;
int findset(int x) {
  if (x!=p[x]) p[x]=findset(p[x]);
  return p[x];
}
int main() {
  scanf("%d%d",&n,&m); r=1;
  for (i=1; i<=n; i++) p[i]=i;
  while (m--) {
    scanf("%d%d",&x,&y);
    x=findset(x);
    y=findset(y);
    if (x==y) {
      r+=r;
      if (r>=md) r-=md;
    } else p[x]=y;
    if (r==0) printf("%d\n",md-1); else printf("%d\n",r-1);
  }
  return 0;
}