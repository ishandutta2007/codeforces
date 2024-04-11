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

const int maxn = 1123;
const int MOD = 998244353;

vector<int> G[maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), in(n + 1);
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) G[i].clear();
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].eb(y);
    in[y]++;
  }
  FOR(i, 1, n) {
    vector<int> v;
    FOR(j, 1, n) if (a[j]) v.eb(j);
    if (v.empty()) {
      cout << i - 1 << '\n';
      return;
    }
    for (auto j : v) {
      a[j]--;
      for (auto k : G[j]) a[k]++;
    }
  }
  queue<int> q;
  FOR(i, 1, n) if (!in[i]) q.emplace(i);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : G[u]) {
      a[v] = (a[u] + a[v]) % MOD;
      if (!--in[v]) q.emplace(v);
    }
  }
  FOR(i, 1, n) if (G[i].empty()) {
    cout << (n + a[i]) % MOD << '\n';
    return;
  }
  assert(0);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}