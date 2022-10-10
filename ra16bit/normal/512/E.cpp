#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,t,i,j,x,y,an,bn;
pair<int,int> a[2020],b[2020];
bool g[1010][1010];
void add(int l, int r, int x) {
  //printf("%d add %d %d %d\n",t,l,r,x);
  g[l][r]=g[r][l]=false;
  g[1][x]=g[x][1]=true;
  if (t) b[bn++]=make_pair(1,x); else a[an++]=make_pair(l,r);
}
void go(int l, int r) {
  if (l+1==r) return;
  //printf("%d go %d %d\n",t,l,r);
  if (l+2==r) {
    add(l,r,l+1);
    return;
  }
  if (g[l+1][r]) {
    add(l,r,l+1);
    go(l+1,r);
    return;
  }
  if (g[l][r-1]) {
    add(l,r,r-1);
    go(l,r-1);
    return;
  }
  for (int j=l+2; j<=r-2; j++) if (g[l][j] && g[j][r]) {
    add(l,r,j);
    go(l,j);
    go(j,r);
  }
}
void solve() {
  int p=2;
  for (int i=3; i<n; i++) if (g[1][i]) {
    go(p,i); p=i;
  }
  go(p,n);
}
int main() {
  scanf("%d",&n); m=n-3;
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x][y]=g[y][x]=true;
  }
  solve(); t=1;
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) g[i][j]=false;
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x][y]=g[y][x]=true;
  }
  solve();
  printf("%d\n",an+bn);
  for (i=0; i<an; i++) printf("%d %d\n",a[i].first,a[i].second);
  for (i=bn-1; i>=0; i--) printf("%d %d\n",b[i].first,b[i].second);
  return 0;
}