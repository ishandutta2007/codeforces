#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m,c,cnt,i,j,k,prv,gap,res,a[1010],b[1000100],z[1000100],f[1010][1010];
long long r[1000100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) for (j=0; j<i; j++) b[++c]=a[i]-a[j];
  sort(b,b+c+1);
  for (k=0; k<=c; k++) if (k==0 || b[k]!=b[k-1]) {
    gap=b[k];
    for (i=prv=0; i<n; i++) {
      for (j=0; j<=m; j++) f[i+1][j]=f[i][j];
      f[i+1][1]=(f[i+1][1]+1)%md;
      if (a[i]-a[0]>=gap) {
        for (; prv<i && a[i]-a[prv]>=gap; prv++);
        if (prv>0) for (j=2; j<=m; j++) f[i+1][j]=(f[i+1][j]+f[prv][j-1])%md;
      }
    }
    if (f[n][m]==0) break;
    z[cnt]=gap;
    r[cnt++]=f[n][m];
  }
  for (i=0; i<cnt; i++) {
    r[i]=(r[i]+md-r[i+1])%md;
    res=(res+r[i]*z[i])%md;
  }
  printf("%d\n",res);
  return 0;
}