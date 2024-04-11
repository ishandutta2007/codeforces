#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,a[505][505],s;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&a[n-i-1][m-j-1]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    if (a[i][j]==0) {
      a[i][j]=10000;
      if (i>0) a[i][j]=min(a[i][j],a[i-1][j]-1);
      if (j>0) a[i][j]=min(a[i][j],a[i][j-1]-1);
    }
    if (i>0 && a[i][j]>=a[i-1][j]) { puts("-1"); return 0; }
    if (j>0 && a[i][j]>=a[i][j-1]) { puts("-1"); return 0; }
    s+=a[i][j];
  }
  printf("%d\n",s);
  return 0;
}