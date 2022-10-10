#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,m,k,i,it,u[MX],x[MX],y[MX],tot,fi,fr,q[MX*2],all[MX];
set<int> g[MX];
void movequeue(int z) {
  while (fi<fr) {
    int x=q[fi++];
    for (int nxt: g[x]) {
      g[nxt].erase(x);
      if (g[nxt].size()==z) q[fr++]=nxt;
    }
    g[x].clear();
  }
}
void solve(int k) {
  for (i=1; i<=n; i++) g[i].clear();
  for (i=0; i<m; i++) {
    g[x[i]].insert(y[i]);
    g[y[i]].insert(x[i]);
  }
  fi=fr=0;
  for (int i=1; i<=n; i++) if (g[i].size()<k) q[fr++]=i;
  movequeue(k-1);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&m,&k);
    for (i=0; i<m; i++) scanf("%d%d",&x[i],&y[i]);
    solve(k);
    if (fr!=n) {
      printf("1 %d\n",n-fr);
      for (i=1; i<=n; i++) if (g[i].size()>=k) printf("%d ",i);
      puts("");
    } else if (k*(k-1LL)<=m*2LL) {
      solve(k-1);
      if (fr!=n) {
        fi=fr=MX;
        for (i=1; i<=n; i++) if (g[i].size()==k-1) q[fr++]=i;
        for (; fi<fr; fi++) {
          all[0]=i=q[fi];
          tot=1;
          ++it;
          u[i]=it;
          for (int nxt: g[i]) if (g[nxt].size()>=k-1) {
            all[tot++]=nxt;
            u[nxt]=it;
          }
          if (tot>=k) {
            //for (int nxt: g[i]) if (u[nxt]==it) for (int oth: g[nxt]) if (u[oth]==it) ++cnt[oth];
            bool ok=true;
            for (int j=0; ok && j<tot; j++) {
              const set<int>& G=g[all[j]];
              if (G.size()<4*j) {
                int cnt=0;
                for (int nxt: G) if (u[nxt]==it) ++cnt;
                ok&=(cnt==k-1);
              } else {
                for (int e=0; ok && e<j; e++) if (!G.count(all[e])) ok=false;
              }
            }
            if (ok) {
              puts("2");
              for (int j=0; j<tot; j++) printf("%d ",all[j]);
              puts("");
              break;
            }
          }
          for (int nxt: g[i]) if (g[nxt].size()>=k-1) {
            g[nxt].erase(i);
            if (g[nxt].size()==k-1) q[fr++]=nxt;
            if (g[nxt].size()<k-1) q[--fi]=nxt;
          }
          g[i].clear();
        }
        if (fi>=fr) puts("-1");
      } else puts("-1");
    } else puts("-1");
  }
  return 0;
}