#include <bits/stdc++.h>
using namespace std;
int t,it,n,i,j,cnt,f[2020][2020],a[5050],nxt[5050],pos[5050],was[5050];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
    for (i=0; i<2*n; i++) scanf("%d",&a[i]);
    for (i=2*n-1; i>=0; i--) {
      nxt[i]=2*n;
      for (j=a[i]+1; j<=2*n; j++) if (was[j]==it) nxt[i]=min(nxt[i],pos[j]);
      was[a[i]]=it;
      pos[a[i]]=i;
    }
    f[0][0]=it;
    for (i=0; i<=n; i++) for (j=0; j<=n; j++) if (f[i][j]==it && i+j<2*n) {
      cnt=nxt[i+j]-i-j;
      if (i+cnt<=n) f[i+cnt][j]=it;
      if (j+cnt<=n) f[i][j+cnt]=it;
    }
    puts((f[n][n]==it)?"YES":"NO");
  }
  return 0;
}