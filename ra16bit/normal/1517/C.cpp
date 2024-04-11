#include <bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};
int n,i,j,x,y,nx,ny,d,cur,a[505][505];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&cur);
    x=y=i;
    a[x][y]=cur;
    for (--cur; cur>0; --cur) {
      for (d=0; d<4; d++) {
        nx=x+dx[d];
        ny=y+dy[d];
        if (nx>0 && nx<=n && ny>0 && ny<=nx && a[nx][ny]==0) break;
      }
      a[x=nx][y=ny]=a[i][i];
    }
  }
  for (i=1; i<=n; i++, puts("")) for (j=1; j<=i; j++) printf("%d ",a[i][j]);
  return 0;
}