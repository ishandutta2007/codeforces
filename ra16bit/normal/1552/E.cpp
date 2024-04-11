#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,mx,rx[102],ry[102],prv[102],cnt[102*102];
bool u[102];
int main() {
  scanf("%d%d",&n,&m);
  mx=(n+m-2)/(m-1);
  for (i=1; i<=n*m; i++) {
    scanf("%d",&x);
    if (!u[x] && prv[x]>0) {
      for (j=prv[x]; j<i; j++) if (cnt[j]>=mx) break;
      if (j>=i) {
        rx[x]=prv[x];
        ry[x]=i;
        for (j=prv[x]; j<=i; j++) ++cnt[j];
        u[x]=true;
      }
    }
    prv[x]=i;
  }
  for (i=1; i<=n; i++) printf("%d %d\n",rx[i],ry[i]);
  return 0;
}