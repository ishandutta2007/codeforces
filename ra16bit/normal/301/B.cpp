#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,m,i,j,it,h,l,ri,r,w,z,a[111],d[111][111],u[111],f[111],x[111],y[111];
int main() {
  scanf("%d%d",&n,&m);
  for (i=2; i<n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&x[i],&y[i]);
	for (j=1; j<i; j++) d[i][j]=d[j][i]=m*(abs(x[i]-x[j])+abs(y[i]-y[j]));
  }
  l=0; ri=100000000;
  while (l<ri) {
    h=(l+ri)/2; ++it;
	memset(f,255,sizeof(f));
	a[1]=f[1]=h;
    while (true) {
	  for (r=-1, i=1; i<=n; i++) if (u[i]!=it && f[i]>r) { r=f[i]; w=i; }
	  if (r==f[n]) break;
	  u[w]=it;
	  for (i=1; i<=n; i++) {
	    z=f[w]-d[w][i]+a[i];
	    if (u[i]!=it && z>f[i]) f[i]=z;
	  }
    }
	if (r<0) l=h+1; else ri=h;
  }
  printf("%d\n",ri);
  return 0;
}