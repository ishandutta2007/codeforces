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

using atcoder::dsu;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (auto &[u, v, w] : edges) {
    cin >> u >> v >> w;
    u--, v--;
    w += w;
  }
  vector<int> pivots(1, 0);
  REP(i, m) FOR(j, i, m - 1) pivots.eb((get<2>(edges[i]) + get<2>(edges[j])) / 2);
  sort(all(pivots));
  uni(pivots);
  vector<ll> ans;
  vector<int> dec;
  for (auto x : pivots) {
    sort(all(edges), [=](const auto &a, const auto &b) {
      int w1 = get<2>(a), w2 = get<2>(b);
      int wa = abs(w1- x), wb = abs(w2 - x);
      if (wa != wb) return wa < wb;
      return w1 > w2;
    });
    auto s = dsu(n);
    ll now = 0;
    int cnt = 0;
    for (auto [u, v, w] : edges) if (!s.same(u, v)) {
      now += abs(w - x);
      cnt += x < w;
      s.merge(u, v);
    }
    ans.eb(now);
    dec.eb(cnt);
  }
  int p, k, a, b, c;
  cin >> p >> k >> a >> b >> c;
  int x;
  ll sum = 0;
  REP(i, k) {
    if (i < p) cin >> x;
    else x = (ll(x) * a + b) % c;
    int id = upper_bound(all(pivots), 2 * x) - pivots.begin() - 1;
    ll cur = ans[id] + ll(n - 1 - 2 * dec[id]) * (2 * x - pivots[id]);
    sum ^= cur / 2;
  }
  cout << sum;
}