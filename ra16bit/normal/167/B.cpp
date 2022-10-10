#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,l,m,ii,i1,i,j,k,p[202],a[202];
double f[2][202][502],r;
int main() {
  scanf("%d%d%d",&n,&l,&m);
  for (i=0; i<n; i++) scanf("%d",&p[i]);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  f[0][0][min(500,250+m)]=1.0;
  for (i=0; i<n; i++) {
    ii=i&1; i1=1-ii;
    memset(f[i1],0,sizeof(f[i1]));
    for (k=0; k<=i; k++) for (j=0; j<=500; j++) if (f[ii][k][j]>0) {
      f[i1][k][j]+=0.01*(100-p[i])*f[ii][k][j];
      f[i1][k+1][max(0,min(500,j+a[i]))]+=0.01*p[i]*f[ii][k][j];
    }
  }
  for (k=l; k<=n; k++) for (j=250; j<=500; j++) if (f[n&1][k][j]>0) r+=f[n&1][k][j];
  printf("%.8lf\n",r);
  return 0;
}