#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,q,i,j,x,y,z,l,r,cur,best,a[1010][1010],up[1010][1010],dn[1010][1010],le[1010][1010],ri[1010][1010];
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
    scanf("%d",&a[i][j]);
    up[i][j]=(up[i-1][j]+1)*a[i][j];
    le[i][j]=(le[i][j-1]+1)*a[i][j];
  }
  for (i=n; i>0; i--) for (j=m; j>0; j--) {
    dn[i][j]=(dn[i+1][j]+1)*a[i][j];
    ri[i][j]=(ri[i][j+1]+1)*a[i][j];
  }
  while (q--) {
    scanf("%d%d%d",&z,&x,&y);
    if (z==1) {
      a[x][y]=1-a[x][y];
      for (i=1; i<=n; i++) up[i][y]=(up[i-1][y]+1)*a[i][y];
      for (j=1; j<=m; j++) le[x][j]=(le[x][j-1]+1)*a[x][j];
      for (i=n; i>0; i--) dn[i][y]=(dn[i+1][y]+1)*a[i][y];
      for (j=m; j>0; j--) ri[x][j]=(ri[x][j+1]+1)*a[x][j];
    } else {
      l=y-1; r=y+1;
      cur=up[x][y];
      while (l>0 && up[x][l]>=cur) l--;
      while (r<=m && up[x][r]>=cur) r++;
      best=cur*(r-l-1);
      while (l>0 || r<=m) {
        cur=min(cur,max(up[x][l],up[x][r]));
        while (l>0 && up[x][l]>=cur) l--;
        while (r<=m && up[x][r]>=cur) r++;
        best=max(best,cur*(r-l-1));
      }
      l=y-1; r=y+1;
      cur=dn[x][y];
      while (l>0 && dn[x][l]>=cur) l--;
      while (r<=m && dn[x][r]>=cur) r++;
      best=max(best,cur*(r-l-1));
      while (l>0 || r<=m) {
        cur=min(cur,max(dn[x][l],dn[x][r]));
        while (l>0 && dn[x][l]>=cur) l--;
        while (r<=m && dn[x][r]>=cur) r++;
        best=max(best,cur*(r-l-1));
      }
      l=x-1; r=x+1;
      cur=le[x][y];
      while (l>0 && le[l][y]>=cur) l--;
      while (r<=n && le[l][y]>=cur) r++;
      best=max(best,cur*(r-l-1));
      while (l>0 || r<=n) {
        cur=min(cur,max(le[l][y],le[r][y]));
        while (l>0 && le[l][y]>=cur) l--;
        while (r<=n && le[r][y]>=cur) r++;
        best=max(best,cur*(r-l-1));
      }
      l=x-1; r=x+1;
      cur=ri[x][y]; 
      while (l>0 && ri[l][y]>=cur) l--;
      while (r<=n && ri[l][y]>=cur) r++;
      best=max(best,cur*(r-l-1));
      while (l>0 || r<=n) {
        cur=min(cur,max(ri[l][y],ri[r][y]));
        while (l>0 && ri[l][y]>=cur) l--;
        while (r<=n && ri[r][y]>=cur) r++;
        best=max(best,cur*(r-l-1));
      }
      printf("%d\n",best);
    }
  }
  return 0;
}