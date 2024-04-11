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

int n, m;
set<pii> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  map<pii, int> edges;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u > v) swap(u, v);
    G[u].emplace(w, v);
    G[v].emplace(w, u);
    edges[mp(u, v)] = w;
  }
  set<tuple<int, int, int>> q;
  auto push = [&](int i) {
    int cnt = 0;
    for (auto it = G[i].begin(); it != G[i].end() && cnt < 3; ++it, ++cnt) {
      int j = it->_2, c = 0;
      for (auto it2 = G[j].begin(); it2 != G[j].end() && c < 3; ++it2, ++c) if (it2->_2 == i) {
        q.emplace(it->_1, min(i, j), max(i, j));
        break;
      }
    }
  };
  auto pop = [&](int i) {
    int cnt = 0;
    for (auto it = G[i].begin(); it != G[i].end() && cnt < 3; ++it, ++cnt) {
      int j = it->_2;
      q.erase(make_tuple(it->_1, min(i, j), max(i, j)));
    }
  };
  FOR(i, 1, n) if (!G[i].empty()) push(i);
  auto query = [&] {
    ll ans = 1e18;
    auto [w, u, v] = *q.begin();
    for (auto [w2, x, y] : q) {
      if (x == u || x == v || y == u || y == v) continue;
      chkmin(ans, ll(w) + w2);
      break;
    }
    vector<tuple<ll, int, int>> eu, ev;
    int cnt = 0;
    ll now = w;
    for (auto [w2, x] : G[u]) {
      if (x == v) continue;
      now += w2;
      eu.eb(w2, u, x);
      if (++cnt == 2) break;
    }
    if (cnt == 2) chkmin(ans, now);
    now = w;
    cnt = 0;
    for (auto [w2, x] : G[v]) {
      if (x == u) continue;
      now += w2;
      ev.eb(w2, v, x);
      if (++cnt == 2) break;
    }
    if (cnt == 2) chkmin(ans, now);
    for (auto [w1, a, b] : eu) for (auto [w2, c, d] : ev) {
      if (a == c || a == d || b == c || b == d) continue;
      chkmin(ans, w1 + w2);
    }
    return ans;
  };
  auto add = [&](int u, int v, int w) {
    if (u > v) swap(u, v);
    pop(u), pop(v);
    G[u].emplace(w, v);
    G[v].emplace(w, u);
    edges[mp(u, v)] = w;
    push(u); push(v);
  };
  auto remove = [&](int u, int v) {
    if (u > v) swap(u, v);
    pop(u), pop(v);
    auto w = edges[mp(u, v)];
    G[u].erase(mp(w, v));
    G[v].erase(mp(w, u));
    edges.erase(mp(u, v));
    push(u), push(v);
  };
  cout << query() << '\n';
  int Q; cin >> Q;
  while (Q--) {
    int op, u, v;
    cin >> op >> u >> v;
    if (op == 0) remove(u, v);
    else {
      int w; cin >> w;
      add(u, v, w);
    }
    cout << query() << '\n';
  }
}