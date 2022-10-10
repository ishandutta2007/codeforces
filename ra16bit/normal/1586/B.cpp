#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,y,z,i,j,it,u[100100];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d",&n,&m);
    for (i=0; i<m; i++) {
      scanf("%d%d%d",&x,&y,&z);
      u[y]=it;
    }
    for (i=1; i<=n; i++) if (u[i]!=it) {
      for (j=1; j<=n; j++) if (i!=j) printf("%d %d\n",i,j);
      break;
    }
  }
  return 0;
}