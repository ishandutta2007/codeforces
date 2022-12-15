#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1000003

int n, u, v, t, ans[100005], vst[100005];
vector<int> ret;
vector<pair<int, int> > adj[100005];

void dfs(int x) {
  // BUG(x);
  vst[x] = 1;
  for (auto p: adj[x]) if (!vst[p._1]) {
    dfs(p._1);
    if (!ans[p._1]) {
      // BUG(p._1);
      if (p._2) {
        ret.pb(p._1);
        ans[x]++;
      }
    } else {
      ans[x] = 1;
    }
  }
  // BUG(x);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  REP (i, n - 1) {
    cin >> u >> v >> t;
    adj[u].pb({v, t - 1});
    adj[v].pb({u, t - 1});
  }
  dfs(1);
  // BUG(ans[1]);
  cout << ret.size() << endl;
  for (int i: ret) cout << i << ' ';
}