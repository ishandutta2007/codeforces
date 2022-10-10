#include <bits/stdc++.h>
using namespace std;
const int MX=400400,md=1000000007;
int t,cur,n,i,x,p[MX],rk[MX],was[MX];
int fs(int x) {
  if (p[x]!=x) p[x]=fs(p[x]);
  return p[x];
}
void un(int x, int y) {
  if (x==y) return;
  if (rk[x]>=rk[y]) {
    p[y]=x;
    if (rk[x]==rk[y]) ++rk[x];
  } else p[x]=y;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
      scanf("%d",&x);
      p[i]=i;
      rk[i]=0;
      was[x]=i;
    }
    for (i=1; i<=n; i++) {
      scanf("%d",&x);
      un(fs(i),fs(was[x]));
    }
    for (cur=i=1; i<=n; i++) if (fs(i)==i) cur=(cur*2)%md;
    printf("%d\n",cur);
  }
  return 0;
}