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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  vector<tuple<int, int, int>> constraints(q);
  for (auto &[i, j, x] : constraints) cin >> i >> j >> x;
  auto solve = [&](int i) {
    vector<int> b(n + 1, -1);
    vector<vector<int>> G(n + 1);
    for (auto [u, v, x] : constraints) {
      if ((x & (1 << i)) == 0) b[u] = b[v] = 0;
      else if (u == v) b[u] = 1;
    }
    for (auto [u, v, x] : constraints) if ((x & (1 << i)) && u != v) {
      if (u > v) swap(u, v);
      if (b[v] == 0) b[u] = 1;
      else G[v].eb(u);
    }
    FOR(j, 1, n) {
      if (b[j] == -1) {
        b[j] = 0;
        for (auto k : G[j]) if (b[k] == 0) {
          b[j] = 1;
          break;
        }
      }
      a[j] |= b[j] << i;
    }
  };
  ROF(i, 29, 0) solve(i);
  FOR(i, 1, n) cout << a[i] << ' ';
}