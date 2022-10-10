#include <bits/stdc++.h>
using namespace std;
const int MX=1010;
int n,q,m,x,y,mx,i,z,r,p[MX],sz[MX],rk[MX],all[MX];
int fs(int x) {
  if (p[x]!=x) p[x]=fs(p[x]);
  return p[x];
}
bool un(int x, int y) {
  if (x==y) return false;
  if (rk[x]>=rk[y]) {
    p[y]=x;
    sz[x]+=sz[y];
    mx=max(mx,sz[x]);
    if (rk[x]==rk[y]) ++rk[x];
  } else {
    p[x]=y;
    sz[y]+=sz[x];
    mx=max(mx,sz[y]);
  }
  return true;
}
int main() {
  scanf("%d%d",&n,&q);
  for (i=1; i<=n; i++) {
    p[i]=i;
    sz[i]=1;
  }
  mx=1;
  while (q--) {
    scanf("%d%d",&x,&y);
    if (!un(fs(x),fs(y))) ++z;
    m=0;
    for (i=1; i<=n; i++) if (fs(i)==i) all[m++]=sz[i];
    sort(all,all+m);
    reverse(all,all+m);
    for (r=i=0; i<m && i<=z; i++) r+=all[i];
    printf("%d\n",r-1);
  }
  return 0;
}