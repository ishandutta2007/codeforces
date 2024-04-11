#include <bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int t,n,m,i,j,d,nx,ny,a[505][505],b[505][505];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    bool ok=true;
    for (i=0; i<n; i++) for (j=0; j<m; j++) {
      scanf("%d",&a[i][j]);
      for (b[i][j]=d=0; d<4; d++) {
        nx=i+dx[d];
        ny=j+dy[d];
        if (nx>=0 && nx<n && ny>=0 && ny<m) ++b[i][j];
      }
      if (b[i][j]<a[i][j]) ok=false;
    }
    if (ok) {
      puts("YES");
      for (i=0; i<n; i++) for (j=0; j<m; j++) printf("%d%c",b[i][j],(j==m-1)?'\n':' ');
    } else puts("NO");
  }
  return 0;
}