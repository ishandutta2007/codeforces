#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

int n, c[maxn];
vector<int> G[maxn];

void dfs(int u, int now) {
  c[u] = now;
  for (auto v : G[u]) if (c[v] == -1) dfs(v, 1 - now);
}

void solve() {
  cin >> n;
  FOR(i, 1, n) {
    G[i].clear();
    c[i] = -1;
  }
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  int cnt[2] = {};
  FOR(i, 1, n) cnt[c[i]]++;
  int chosen = cnt[0] <= cnt[1] ? 0 : 1;
  vector<int> good, bad;
  for (int j = 0; (1 << j) <= n; j++) {
    if ((1 << j) & cnt[chosen]) FOR(i, (1 << j), min(n, (2 << j) - 1)) good.eb(i);
    else FOR(i, (1 << j), min(n, (2 << j) - 1)) bad.eb(i);
  }
  FOR(i, 1, n) {
    if (c[i] == chosen) {
      cout << good.back() << ' ';
      good.pop_back();
    } else {
      cout << bad.back() << ' ';
      bad.pop_back();
    }
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}