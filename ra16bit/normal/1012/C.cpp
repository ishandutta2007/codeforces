#include <bits/stdc++.h>
using namespace std;
const int inf=1000100100;
int n,tot,mx,pcur,cur,i,j,a[5005],f[5005][5005],s[5005][5005];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  tot=(n+1)/2;
  for (j=1; j<=tot; j++) f[0][j]=s[0][j]=inf;
  for (i=1; i<=n; i++) {
    pcur=max(0,a[i+1]-a[i]+1);
    f[i][1]=cur=max(0,a[i-1]-a[i]+1)+pcur;
    if (i>=2) pcur+=max(0,min(a[i-1],a[i-2]-1)-a[i]+1);
    s[i][1]=min(f[i][1],s[i-1][1]);
    mx=(i+1)/2;
    for (j=2; j<=mx; j++) {
      if (f[i-2][j-1]<inf) f[i][j]=f[i-2][j-1]+pcur; else f[i][j]=inf;
      if (i-3>=0 && s[i-3][j-1]<inf) f[i][j]=min(f[i][j],s[i-3][j-1]+cur);
      s[i][j]=min(f[i][j],s[i-1][j]);
    }
    for (; j<=tot; j++) f[i][j]=s[i][j]=inf;
  }
  for (i=1; i<=tot; i++) printf("%d ",s[n][i]);
  return 0;
}