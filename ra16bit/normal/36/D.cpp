#include <stdio.h>
int i,j,t,n,m,k,z,e,a[100][100];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&t,&k);
  for (i=0; i<t; i++) {
    scanf("%d%d",&n,&m); e=n+m;
    if (k==1) {
      if ((n&1) && (m&1)) puts("-"); else puts("+");
      continue;
    }
    if (m<n) n=m;
    if (n%(k+1)==0) { puts("+"); continue; }
    z=n/(k+1);
    if (z&1) {
      if (e&1) puts("-"); else puts("+");
    } else {
      if (e&1) puts("+"); else puts("-");
    }
  }
  return 0;
}