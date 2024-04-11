#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


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
  int n, m;
  cin >> n >> m;
  if (ll(n) * (n - 1) / 2 >= m + n) {
    vector<vector<int>> G(n);
    vector<tuple<int, int, int>> edges(m);
    REP(i, m) {
      int w, u, v;
      cin >> u >> v >> w;
      u--, v--;
      edges[i] = {w, u, v};
      G[u].eb(v); G[v].eb(u);
    }
    REP(i, n) sort(all(G[i]));
    set<int> rem;
    REP(i, n) rem.emplace(i);
    auto dsu = atcoder::dsu(n);
    while (!rem.empty()) {
      auto u = *rem.begin(); rem.erase(rem.begin());
      vector<int> q; q.eb(u);
      REP(i, int(q.size())) {
        int v = q[i];
        auto it = rem.begin();
        while (it != rem.end()) {
          auto it2 = lower_bound(all(G[v]), *it);
          if (it2 != G[v].end() && *it2 == *it) {
            ++it;
            continue;
          }
          q.eb(*it);
          dsu.merge(u, *it);
          it = rem.erase(it);
        }
      }
    }
    sort(all(edges));
    ll ans = 0;
    for (auto [w, u, v] : edges) if (!dsu.same(u, v)) {
      dsu.merge(u, v);
      ans += w;
    }
    cout << ans;
  } else {
    set<pii> tot;
    REP(i, n) FOR(j, i + 1, n - 1) tot.emplace(i, j);
    int s = 0;
    vector<tuple<int, int, int>> edges(m);
    REP(i, m) {
      int w, u, v;
      cin >> u >> v >> w;
      u--, v--;
      if (u > v) swap(u, v);
      tot.erase(mp(u, v));
      edges[i] = {w, u, v};
      s ^= w;
    }
    ll ans = 1e18;
    edges.eb(s, n, n);
    sort(all(edges));
    for (auto e : tot) {
      auto dsu = atcoder::dsu(n);
      for (auto e2 : tot) if (e2 != e) dsu.merge(e2._1, e2._2);
      ll res = 0;
      for (auto [w, u, v] : edges) {
        if (u == n) {
          if (!dsu.same(e._1, e._2)) {
            res += s;
            dsu.merge(e._1, e._2);
          }
        } else if (!dsu.same(u, v)) {
          res += w;
          dsu.merge(u, v);
        }
      }
      chkmin(ans, res);
    }
    cout << ans;
  }
}