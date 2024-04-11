#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,it,n,r,i,u[MX],st[MX],fin[MX],nxt[MX];
bool e[MX];
void dfs(int j) {
  u[j]=it;
  if (u[nxt[j]]==0) dfs(nxt[j]); else { fin[it]=j; --r; }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
      scanf("%d",&nxt[i]);
      e[i]=true;
      u[i]=0;
    }
    for (i=1; i<=n; i++) e[nxt[i]]=false;
    it=0; r=n;
    for (i=1; i<=n; i++) if (e[i]) { st[++it]=i; dfs(i); }
    if (it>0) {
      for (i=1; i<it; i++) nxt[fin[i]]=st[i+1];
      nxt[fin[it]]=st[1];
    }
    printf("%d\n",r);
    for (i=1; i<=n; i++) printf("%d%c",nxt[i],(i==n)?'\n':' ');
  }
  return 0;
}