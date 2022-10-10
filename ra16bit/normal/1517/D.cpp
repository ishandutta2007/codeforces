#include <bits/stdc++.h>
using namespace std;
const int MX=505,inf=1000000000;
int n,m,k,i,j,e,cur,le[MX][MX],ri[MX][MX],up[MX][MX],dn[MX][MX],dst[12][MX][MX];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  if (k%2) {
    for (i=0; i<n; i++, puts("")) for (j=0; j<m; j++) printf("-1 ");
    return 0;
  }
  k/=2;
  for (i=0; i<n; i++) for (j=1; j<m; j++) {
    scanf("%d",&le[i][j]);
    le[i][j]*=2;
    ri[i][j-1]=le[i][j];
  }
  for (i=1; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&up[i][j]);
    up[i][j]*=2;
    dn[i-1][j]=up[i][j];
  }
  for (e=1; e<=k; e++) {
    for (i=0; i<n; i++) for (j=0; j<m; j++) {
      cur=inf;
      if (i>0) cur=min(cur,up[i][j]+dst[e-1][i-1][j]);
      if (j>0) cur=min(cur,le[i][j]+dst[e-1][i][j-1]);
      if (i+1<n) cur=min(cur,dn[i][j]+dst[e-1][i+1][j]);
      if (j+1<m) cur=min(cur,ri[i][j]+dst[e-1][i][j+1]);
      dst[e][i][j]=cur;
    }
  }
  for (i=0; i<n; i++, puts("")) for (j=0; j<m; j++) printf("%d ",dst[k][i][j]);
  return 0;
}