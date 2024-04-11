#include <stdio.h>
const int mx=400005;
int i,j,n,nn;
long long m,rx,ry,x[mx],y[mx],ax[mx],ay[mx];
int main() {
  scanf("%d%I64d",&n,&m);
  scanf("%I64d%I64d",&x[0],&y[0]);
  for (i=0; i<n; i++) scanf("%I64d%I64d",&ax[i],&ay[i]);
  for (i=j=0; i<400000; i++) {
    x[i+1]=2*ax[j]-x[i];
    y[i+1]=2*ay[j]-y[i];
    if (++j==n) j=0;
  }
  if (m<=400000) { printf("%I64d %I64d\n",x[m],y[m]); return 0; } else nn=(m%n)+n;
  if (x[n+nn]-x[nn]==x[2*n+nn]-x[n+nn] && y[n+nn]-y[nn]==y[2*n+nn]-y[n+nn]) {
    m=(m-nn)/n;
    rx=x[nn]+(x[n+nn]-x[nn])*m;
    ry=y[nn]+(y[n+nn]-y[nn])*m;
  } else if (x[n+nn]-x[nn]==-x[2*n+nn]+x[n+nn] && y[n+nn]-y[nn]==-y[2*n+nn]+y[n+nn]) {
    i=m%(2*n);
    if (i<100) i+=2*n;
    rx=x[i]; ry=y[i];
  } else n/=0;
  printf("%I64d %I64d\n",rx,ry);
  return 0;
}