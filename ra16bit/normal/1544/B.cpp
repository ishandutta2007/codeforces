#include <bits/stdc++.h>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
int t,msk,n,m,cur,r,rit,it,i,j,nx,ny,d,a[22][22],ra[22][22];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (r=msk=0; msk<(1<<12); msk++) {
      ++it;
      if (msk&1) a[1][1]=it;
      if (msk&2) a[1][2]=it;
      if (msk&4) a[2][1]=it;
      if (msk&8) a[1][m]=it;
      if (msk&16) a[1][m-1]=it;
      if (msk&32) a[2][m]=it;
      if (msk&64) a[n-1][1]=it;
      if (msk&128) a[n][1]=it;
      if (msk&256) a[n][2]=it;
      if (msk&512) a[n-1][m]=it;
      if (msk&1024) a[n][m]=it;
      if (msk&2048) a[n][m-1]=it;
      bool ok=true;
      cur=0;
      for (i=1; i<=n && ok; i++) for (j=1; j<=m && ok; j++) if (a[i][j]==it) {
        for (d=0; d<8; d++) {
          nx=i+dx[d];
          ny=j+dy[d];
          if (a[nx][ny]==it) break;
        }
        if (d<4) ok=false;
        ++cur;
      }
      if (ok) {
        for (i=3; i<n-1; i++) {
          if (a[i][1]!=it) {
            for (d=0; d<8; d++) {
              nx=i+dx[d];
              ny=1+dy[d];
              if (a[nx][ny]==it) break;
            }
            if (d>=8) { a[i][1]=it; ++cur; }
          }
          if (a[i][m]!=it) {
            for (d=0; d<8; d++) {
              nx=i+dx[d];
              ny=m+dy[d];
              if (a[nx][ny]==it) break;
            }
            if (d>=8) { a[i][m]=it; ++cur; }
          }
        }
        for (i=3; i<m-1; i++) {
          if (a[1][i]!=it) {
            for (d=0; d<8; d++) {
              nx=1+dx[d];
              ny=i+dy[d];
              if (a[nx][ny]==it) break;
            }
            if (d>=8) { a[1][i]=it; ++cur; }
          }
          if (a[n][i]!=it) {
            for (d=0; d<8; d++) {
              nx=n+dx[d];
              ny=i+dy[d];
              if (a[nx][ny]==it) break;
            }
            if (d>=8) { a[n][i]=it; ++cur; }
          }
        }
        if (cur>r) {
          r=cur;
          rit=it;
          for (i=1; i<=n; i++) for (j=1; j<=m; j++) ra[i][j]=a[i][j];
        }
      }
    }
    for (i=1; i<=n; i++,puts("")) for (j=1; j<=m; j++) printf("%d",int(ra[i][j]==rit));
    puts("");
  }
  return 0;
}