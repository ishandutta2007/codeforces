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
int c[maxn];
bool vis[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> c[i];
  vector<int> cyc;
  FOR(i, 1, n) if (!vis[i]) {
    int j = i;
    while (!vis[j]) {
      vis[j] = true;
      j = c[j];
    }
    cyc.eb(i);
  }
  vector<pii> ans;
  auto solve = [&](int u, int v) {
    while (c[u] != v) {
      ans.eb(u, c[u]);
      swap(c[u], c[c[u]]);
    }
    while (c[v] != u) {
      ans.eb(v, c[v]);
      swap(c[v], c[c[v]]);
    }
    ans.eb(u, v);
    swap(c[u], c[v]);
  };
  if (cyc.size() == 1) {
    int u = cyc[0], v = c[u];
    ans.eb(u, v);
    swap(c[u], c[v]);
    ans.eb(c[u], v);
    swap(c[c[u]], c[v]);
    solve(u, v);
  } else {
    for (int i = 0; i + 1 < cyc.size(); i += 2) {
      ans.eb(cyc[i], cyc[i + 1]);
      swap(c[cyc[i]], c[cyc[i + 1]]);
      solve(cyc[i], cyc[i + 1]);
    }
    if (cyc.size() % 2 == 1) {
      int u = cyc.back(), v = 1;
      while (c[v] != v) v++;
      ans.eb(u, v);
      swap(c[u], c[v]);
      solve(u, v);
    }
  }
  assert(ans.size() <= n + 1);
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
}