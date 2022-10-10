#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,k,z;
long long j,c,l,r,x,y;
double a[1111],f[1111][1111],res;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d%I64d",&l,&r); c=0;
    for (j=z=1; z<=19; j*=10, z++) {
      x=max(l,j);
      y=min(r,j*2-1);
      if (x<=y) c+=y-x+1;
    }
    a[i]=double(c)/double(r-l+1);
  }
  scanf("%d",&k); f[0][0]=1.0;
  for (i=0; i<n; i++) for (j=0; j<=i; j++) {
    f[i+1][j+1]+=f[i][j]*a[i];
    f[i+1][j]+=f[i][j]*(1.0-a[i]);
  }
  for (i=0; i<=n; i++) if (i*100>=k*n) res+=f[n][i];
  printf("%.11lf\n",res);
  return 0;
}