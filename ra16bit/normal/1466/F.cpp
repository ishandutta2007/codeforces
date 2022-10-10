#include <bits/stdc++.h>
using namespace std;
const int MX=500500,md=1000000007;
int n,m,i,j,cnt,r,res=1,a[5],ans[MX],p[MX],rk[MX];
bool w[MX];
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
bool un(int x, int y) {
  if (x==y) return false;
  bool both=(w[x]&w[y]);
  if (rk[x]<=rk[y]) {
    p[x]=y;
    w[y]|=w[x];
    if (rk[x]==rk[y]) ++rk[y];
  } else {
    p[y]=x;
    w[x]|=w[y];
  }
  return !both;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=m; i++) p[i]=i;
  for (i=1; i<=n; i++) {
    scanf("%d",&cnt);
    for (j=0; j<cnt; j++) scanf("%d",&a[j]);
    if (cnt==1) {
      j=fs(a[0]);
      if (!w[j]) { w[j]=true; ans[r++]=i; res=(res*2)%md; }
    } else {
      if (un(fs(a[0]),fs(a[1]))) { ans[r++]=i; res=(res*2)%md; }
    }
  }
  printf("%d %d\n",res,r);
  for (i=0; i<r; i++) printf("%d ",ans[i]);
  return 0;
}