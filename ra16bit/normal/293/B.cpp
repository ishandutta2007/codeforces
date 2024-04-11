#include <cstdio>
#include <algorithm>
using namespace std;
const int md=1000000007;
int n,m,k,i,j,x,y,r,a[22][22],f[22][22],c[22][22],g[22],o[22];
void rec(int i, int j, int w) {
  if (j==m) {
    if (i==n-1) {
	  int e=0,z=0;
      for (int p=1; p<=k; p++) {
	    if (f[n-1][m-1]&(1<<p)) e++;
		if (g[p]!=0) z++;
	  }
	  r=(r+c[k-z][e-z])%md;
	} else rec(i+1,0,w);
	return;
  }
  f[i][j]=0;
  if (i>0) f[i][j]|=f[i-1][j];
  if (j>0) f[i][j]|=f[i][j-1];
  int e=0;
  for (int p=1; p<=k; p++) if ((f[i][j]&(1<<p))==0) e++;
  if (n-i+m-j-1>e) return;
  if (a[i][j]!=0) {
    if (g[a[i][j]]==0) {
	  for (int p=1; p<=w; p++) if ((f[i][j]&(1<<p))==0 && o[p]==0) {
	    f[i][j]^=(1<<p);
	    g[a[i][j]]=p;
	    o[p]=a[i][j];
	    rec(i,j+1,min(k,max(w,p+1)));
	    f[i][j]^=(1<<p);
		g[a[i][j]]=0;
	    o[p]=0;
      }
	} else if ((f[i][j]&(1<<g[a[i][j]]))==0) {
	  f[i][j]^=(1<<g[a[i][j]]);
	  rec(i,j+1,w);
	  f[i][j]^=(1<<g[a[i][j]]);
	}
    return;
  }
  for (int p=1; p<=w; p++) if ((f[i][j]&(1<<p))==0) {
	f[i][j]^=(1<<p);
	rec(i,j+1,min(k,max(w,p+1)));
	f[i][j]^=(1<<p);
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<=k; i++) {
    c[i][0]=1;
	for (j=1; j<=k; j++) c[i][j]=(c[i][j-1]*(i-j+1LL))%md;
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&a[i][j]);
  rec(0,0,1);
  printf("%d\n",r);
  return 0;
}