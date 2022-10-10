#include <cstdio>
using namespace std;
int n,m,i,j,k,a[100100][5],b[100100][5];
long long A[100100][32],B[100100][32],c,f[100100][32],inf=1000000000LL;
int main() {
  scanf("%d%d",&m,&n);
  for (i=1; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a[i][j]);
    for (k=0; k<(1<<m); k++) if (k&(1<<j)) A[i][k]+=a[i][j];
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&b[i][j]);
    if (j<m-1) {
      for (k=0; k<(1<<m); k++) if (((k&(1<<j))!=0)!=((k&(1<<(j+1)))!=0)) B[i][k]+=b[i][j];
    } else {
      for (k=0; k<(1<<m); k++) if (((k&(1<<j))!=0)!=((k&1)!=0)) B[i][k]+=b[i][j];
    }
  }
  inf*=inf;
  for (i=0; i<=n; i++) for (j=0; j<(1<<m); j++) f[i][j]=inf;
  f[1][(1<<m)-1]=0;
  for (i=1; i<n; i++) for (j=0; j<(1<<m); j++) if (f[i][j]<inf) for (k=0; k<(1<<m); k++) if ((j&k)==k) {
    c=f[i][j]+A[i][j^k]+B[i][k];
    if (c<f[i+1][k]) f[i+1][k]=c;
  }
  printf("%I64d\n",f[n][0]);
  return 0;
}