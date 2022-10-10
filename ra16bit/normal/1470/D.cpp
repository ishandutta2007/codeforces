#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,it,n,m,i,x,y,fi,fr,r,ans[MX],q[MX],u[MX],good[MX];
vector<int> g[MX];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=0; i<m; i++) {
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    u[1]=it;
    fi=r=0; q[0]=fr=1;
    while (fi<fr) {
      i=q[fi++];
      bool ok=true;
      for (int j: g[i]) if (u[j]!=it) {
        u[j]=it; q[fr++]=j;
      } else if (good[j]==it) ok=false;
      if (ok) { ans[r++]=i; good[i]=it; }
    }
    if (fr==n) {
      puts("YES");
      printf("%d\n",r);
      for (i=0; i<r; i++) printf("%d%c",ans[i],(i==r-1)?'\n':' ');
    } else puts("NO");
  }
  return 0;
}