#include <bits/stdc++.h>
using namespace std;
const int MX=104;
int t,n,i,j,k,best,tot,it,u[MX],p[MX],cnt[MX],d[MX][MX];
char s[MX][MX][MX];
vector<int> g[MX];
bool dfs(int i, int prv) {
  p[i]=prv;
  u[i]=it;
  ++tot;
  for (int j=0; j<n; j++) if (j!=prv && s[min(prv,j)][max(prv,j)][i]=='1') {
    if (u[j]==it) return false;
    if (!dfs(j,i)) return false;
    g[i].push_back(j);
    g[j].push_back(i);
  }
  return true;
}
void calcdist(int st, int i, int prv, int cur) {
  d[st][i]=cur;
  for (int j: g[i]) if (j!=prv) calcdist(st,j,i,cur+1);
}
bool check() {
  for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=0; k<n; k++) if (s[i][j][k]=='0') {
    if (d[i][k]==d[j][k]) return false;
  } else if (d[i][k]!=d[j][k]) return false;
  return true;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) g[i].reserve(n);
    for (i=0; i<n; i++) for (j=i+1; j<n; j++) scanf("%s",s[i][j]);
    for (best=i=0; i<n; i++) {
      cnt[i]=0;
      u[i]=++it;
      for (j=0; j<n; j++) if (u[j]!=it) {
        u[j]=it;
        ++cnt[i];
        for (k=j+1; k<n; k++) if (s[j][k][i]=='1') u[k]=it;
      }
      if (cnt[i]>cnt[best]) best=i;
    }
    for (i=0; i<n; i++) if (i!=best) {
      u[best]=++it;
      tot=1;
      for (j=0; j<n; j++) g[j].clear();
      g[i].push_back(best);
      g[best].push_back(i);
      if (dfs(i,best) && tot==n) {
        for (j=0; j<n; j++) calcdist(j,j,-1,0);
        if (check()) {
          puts("Yes");
          for (j=0; j<n; j++) if (j!=best) printf("%d %d\n",p[j]+1,j+1);
          break;
        }
      }
    }
    if (i>=n) puts("No");
  }
  return 0;
}