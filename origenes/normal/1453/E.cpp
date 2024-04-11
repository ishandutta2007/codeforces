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

int n;
vector<int> G[maxn];

int dfs(int u, int par, int k) {
  vector<int> vec;
  int cnt = 0;
  if (G[u].size() == 1 && u != 1) return 0;
  for (auto v : G[u]) if (v != par) {
    int x = dfs(v, u, k);
    if (x == -1 || x >= k) return -1;
    if (x == k - 1) cnt++;
    else vec.eb(x);
  }
  if (cnt >= 2) return -1;
  if (cnt == 1) return k;
  return *min_element(all(vec)) + 1;
}

bool check(int k) {
  int x = dfs(1, 0, k);
  return x != -1 && x <= k;
}

void solve() {
  cin >> n;
  FOR(i, 1, n) G[i].clear();
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  cout << lo << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}