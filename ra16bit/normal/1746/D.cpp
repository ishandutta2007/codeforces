#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,m,i,x,a[MX];
long long mn[MX];
vector<int> g[MX];
vector<long long> f[MX];
void dfs(int i, int ma, int mb) {
  mn[i]=ma;
  f[i].resize(mb-ma+1);
  if (!g[i].empty()) {
    int cnt=g[i].size();
    ma=ma/cnt;
    mb=(mb+cnt-1)/cnt;
    for (int j: g[i]) dfs(j,ma,mb);
  }
}
void solve(int i) {
  for (int j=0; j<f[i].size(); j++) f[i][j]=a[i]*(mn[i]+j);
  if (g[i].empty()) return;
  int cnt=g[i].size();
  int nxt=mn[i]/cnt;
  for (int j: g[i]) solve(j);
  vector<long long> v(cnt);
  for (int j=0; j<f[i].size(); j++) {
    int ma=(mn[i]+j)/cnt;
    int mb=(mn[i]+j+cnt-1)/cnt;
    assert(mb>=ma && mb<=ma+1);
    for (int k=0; k<cnt; k++) {
      long long cur=f[g[i][k]][ma-nxt];
      f[i][j]+=cur;
      if (ma!=mb) {
        v[k]=f[g[i][k]][mb-nxt]-cur;
        assert(v[k]>=0);
      }
    }
    if (ma!=mb) {
      sort(v.rbegin(),v.rend());
      int cz=(mn[i]+j)%cnt;
      for (int k=0; k<cz; k++) f[i][j]+=v[k];
    }
    //printf("%d %d = %lld\n",i,mn[i]+j,f[i][j]);
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) g[i].clear();
    for (i=2; i<=n; i++) {
      scanf("%d",&x);
      g[x].push_back(i);
    }
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    dfs(1,m,m);
    solve(1);
    printf("%lld\n",f[1][0]);
  }
  return 0;
}