#include <stdio.h>
int b[722],i,j,n,m,k,p;
long long f[55][1111];
double z;
bool u[55];
int main() {
  scanf("%d",&n);
  for (i=2; i<=50; i++) if (!u[i]) {
    b[++k]=i;
    for (j=i+i; j<=50; j+=i) u[j]=true;
  }
  for (i=1; i<=k; i++) f[i][1]=1;
  for (i=1; i<=k; i++) for (j=1; j<=n; j++) if (f[i][j]) for (p=j,z=f[i][j]; p<=n; p+=j,z*=b[i])
     if (z+1e-9<2*(1e18) && (z+1e-9<f[i+1][p] || f[i+1][p]==0)) f[i+1][p]=(long long)(z+1e-9);
  printf("%I64d\n",f[k][n]);
  return 0;
}