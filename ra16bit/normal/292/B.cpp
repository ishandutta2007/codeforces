#include <stdio.h>
int n,m,i,x,y,v[100100],c[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
	v[x]++; v[y]++;
  }
  for (i=1; i<=n; i++) c[v[i]]++;
  if (c[1]==2 && c[2]==n-2) puts("bus topology"); else
    if (c[1]==n-1 && c[n-1]==1) puts("star topology"); else
      if (c[2]==n) puts("ring topology"); else puts("unknown topology");
  return 0;
}