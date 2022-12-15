#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, par[200005], u, v, cnt[200005], lis[200005], ans, k;
vector<int> adj[200005];
vector<int> res;

void dfs(int x) {
  cnt[x] = lis[x];
  for (int nex: adj[x]) if (nex != par[x]) {
    par[nex] = x;
    dfs(nex);
    cnt[x] += cnt[nex];
  }
}

void dfs2(int x) {
  // BUG(x);
  if (lis[x]) res.pb(x);
  for (int nex: adj[x]) if (nex != par[x]) {
    par[nex] = x;
    dfs2(nex);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  REP (i, n - 1) {
    cin >> u >> v;
    adj[v].pb(u);
    adj[u].pb(v);
  }
  REP (i, 2 * k) {
    cin >> u;
    lis[u] = 1;
  }
  dfs(1);
  ans = 1;
  while (1) {
    bool flag = false;
    for (int nex: adj[ans]) if (nex != par[ans]) if (cnt[nex] > k) {
      ans = nex;
      flag = true;
      break;
    }
    if (!flag) break;
  }
  cout << 1 << endl << ans << endl;
  reset(par, 0);
  dfs2(ans);
  // BUG(res.size());
  REP (i, k) cout << res[i] << ' ' << res[i + k] << ' ' << ans << endl;
}