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

const int maxn = 112345;

int n;
int x[maxn], y[maxn], id[maxn];
ll f[maxn];
vector<pii> G[maxn];

int main() {
  int _; scanf("%d%d", &_, &n);
  scanf("%d%d%d%d", x, y, x + n + 1, y + n + 1);
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  reset(f, 0x3f); f[0] = 0;
  iota(id + 1, id + n + 1, 1);
  FOR(i, 1, n) G[0].eb(i, min(abs(x[0] - x[i]), abs(y[0] - y[i])));
  REP(i, n + 1) G[i].eb(n + 1, abs(x[i] - x[n + 1]) + abs(y[i] - y[n + 1]));
  sort(id + 1, id + n + 1, [](int i, int j) { return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]; });
  FOR(i, 2, n) {
    G[id[i]].eb(id[i - 1], min(abs(x[id[i]] - x[id[i - 1]]), abs(y[id[i]] - y[id[i - 1]])));
    G[id[i - 1]].eb(id[i], min(abs(x[id[i]] - x[id[i - 1]]), abs(y[id[i]] - y[id[i - 1]])));
  }
  sort(id + 1, id + n + 1, [](int i, int j) { return y[i] == y[j] ? x[i] < x[j] : y[i] < y[j]; });
  FOR(i, 2, n) {
    G[id[i]].eb(id[i - 1], min(abs(x[id[i]] - x[id[i - 1]]), abs(y[id[i]] - y[id[i - 1]])));
    G[id[i - 1]].eb(id[i], min(abs(x[id[i]] - x[id[i - 1]]), abs(y[id[i]] - y[id[i - 1]])));
  }
  set<pair<ll, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [d, u] = *q.begin(); q.erase(q.begin());
    if (f[u] != d) continue;
    for (auto [v, c] : G[u]) {
      ll nd = d + c;
      if (nd < f[v]) {
        q.emplace(nd, v);
        f[v] = nd;
      }
    }
  }
  printf("%lld", f[n + 1]);
}