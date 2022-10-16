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

int n, k;
vector<int> G[maxn], leaves;

int dfs(int u, int par) {
  vector<int> ch;
  for (auto v : G[u]) if (v != par) ch.eb(dfs(v, u) + 1);
  if (ch.empty()) return 0;
  auto it = max_element(all(ch));
  int ret = *it; ch.erase(it);
  copy(all(ch), back_inserter(leaves));
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  leaves.eb(dfs(1, 0) + 1);
  auto f = [](int red, int blue) {
    ll w = n - red - blue;
    return w * (red - blue);
  };
  if (size(leaves) <= k) {
    int red = max(int(size(leaves)), min(k, n / 2));
    cout << f(red, 0);
    return 0;
  }
  sort(all(leaves), greater<>());
  leaves.resize(k);
  int tot = accumulate(all(leaves), 0);
  cout << f(size(leaves), min(n / 2, n - tot));
}