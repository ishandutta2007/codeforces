#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,ii,a[505][505],x[505];
long long ans[505];
bool u[505];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) scanf("%d",&a[i][j]);
  for (i=1; i<=n; i++) scanf("%d",&x[i]);
  for (ii=n; ii>0; ii--) {
    k=x[ii];
	u[k]=true;
	for (j=1; j<=n; j++) if (u[j]) for (i=1; i<=n; i++) if (u[i]) {
	  a[i][k]=min(a[i][k],a[i][j]+a[j][k]);
	  a[k][i]=min(a[k][i],a[k][j]+a[j][i]);
	}
	for (i=1; i<=n; i++) if (u[i]) for (j=1; j<=n; j++) if (u[j]) {
	  a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	  ans[ii]+=a[i][j];
	}
  }
  for (i=1; i<=n; i++) printf("%I64d%c",ans[i],i==n?'\n':' ');
  return 0;
}