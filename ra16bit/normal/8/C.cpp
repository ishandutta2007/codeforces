#include <cstdio>
using namespace std;
int i,j,k,e,p,n,xx,yy,x[25],y[25],f[1<<24],g[1<<24],a[25][25],d[25];
int main() {
  scanf("%d%d",&xx,&yy);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    d[i]=(x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy);
    for (j=0; j<i; j++) a[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
  }
  for (i=0; i<(1<<n); i++) if (i==0 || f[i]>0) {
    for (j=0; j<n; j++) if ((i&(1<<j))==0) {
      p=i+(1<<j);
	  if (f[p]==0 || f[i]+d[j]*2<f[p]) { f[p]=f[i]+d[j]*2; g[p]=i; }
      for (k=j+1; k<n; k++) if (((i&(1<<k))==0)) {
        e=d[j]+d[k]+a[j][k];
        p=i+(1<<j)+(1<<k);
		if (f[p]==0 || f[i]+e<f[p]) { f[p]=f[i]+e; g[p]=i; }
      }
      break;
    }
  }
  i=(1<<n)-1;
  printf("%d\n",f[i]);
  while (i>0) {
	  printf("0 ");
	  for (j=0; j<n; j++) if ((g[i]&(1<<j))==0 && (i&(1<<j))!=0) printf("%d ",j+1);
	  i=g[i];
  }
  puts("0");
  return 0;
}