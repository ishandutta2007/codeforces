#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,m;
double l,r,h,p[2005],f[2005],g[2005],eps=1e-8;
void bf() {
  for (int k=0; k<m; k++) for (int i=0; i<=m; i++) if (f[i]<1e19) for (int j=0; j<=i && j<=n; j++) {
    int e=i-j+n-j;
	if (e<=m) f[e]=min(f[e],f[i]+h-p[j]);
  }
}
int main() {
  scanf("%d",&n); m=3*n;
  for (i=0; i<=n; i++) scanf("%lf",&p[i]);
  l=0; r=1;
  while (l<r-eps) {
    h=(l+r)*0.5;
	f[0]=0;
	for (i=1; i<=m; i++) f[i]=1e20;
	bf();
	for (i=0; i<=m; i++) g[i]=f[i];
	bf();
	for (i=0; i<=m; i++) if (f[i]<g[i]-eps) break;
	if (i>m) r=h; else l=h;
  }
  printf("%.10lf\n",0.5*(l+r));
  return 0;
}