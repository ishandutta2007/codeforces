#include <stdio.h>
int m,v,i,j,z;
long long n;
int main() {
  scanf("%I64d%d%d",&n,&m,&v);
  if (v==n) z=n-1; else z=n;
  if (m<n-1 || m>((n-2)*(n-1))/2+1) { puts("-1"); return 0; }
  for (i=1; i<=n; i++) if (i!=v) printf("%d %d\n",i,v);
  m-=n-1;
  for (i=1; i<=n; i++) if (i!=v && i!=z) {
    for (j=i+1; j<=n; j++) if (m>0 && j!=v && j!=z) { printf("%d %d\n",i,j); m--; }
    if (m==0) break;
  }
  return 0;
}