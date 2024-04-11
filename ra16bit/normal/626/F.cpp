#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,m,i,j,k,cur,r,a[202],f[202][202][1002];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  f[0][0][0]=1;
  for (i=0; i<n; i++) for (j=0; j<=i; j++) {
    if (j) cur=(a[i]-a[i-1])*j; else cur=0;
    for (k=0; k+cur<=m; k++) if (f[i][j][k]) {
      int &c=f[i+1][j][k+cur];
      c+=f[i][j][k];
      if (c>=md) c-=md;
      if (n-i-1>j) {
        int &c=f[i+1][j+1][k+cur];
        c+=f[i][j][k];
        if (c>=md) c-=md;
      }
      if (j) {
        int x=(1LL*j*f[i][j][k])%md;
        if (n-i-1>=j) {
          int &c=f[i+1][j][k+cur];
          c+=x; if (c>=md) c-=md;
        }
        int &c=f[i+1][j-1][k+cur];
        c+=x; if (c>=md) c-=md;
      }
    }
  }
  for (k=0; k<=m; k++) {
    r+=f[n][0][k];
    if (r>=md) r-=md;
  }
  printf("%d\n",r);
  return 0;
}