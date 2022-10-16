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

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  int ans = 0;
  REP(i, n) {
    cin >> a[i];
    if (a[i] == 0) {
      a[i] = 1;
      ans++;
    }
  }
  auto print = [&]() {
    cout << ans << '\n';
    for (auto x : a) cout << x << ' ';
    cout << '\n';
  };
  auto connected = [n](const vector<int> &a) {
    atcoder::dsu dsu(30);
    vector<bool> vis(30);
    REP(i, n) {
      vector<int> pos;
      REP(j, 30) if (a[i] & (1 << j)) {
        pos.eb(j);
        vis[j] = true;
      }
      FOR(j, 1, int(size(pos)) - 1) dsu.merge(pos[j - 1], pos[j]);
    }
    set<int> ccs;
    REP(i, 30) if (vis[i]) ccs.emplace(dsu.leader(i));
    return ccs.size() == 1;
  };
  if (connected(a)) {
    print();
    return;
  }
  ans++;
  REP(i, n) {
    a[i]++;
    if (connected(a)) {
      print();
      return;
    }
    a[i] -= 2;
    if (a[i] && connected(a)) {
      print();
      return;
    }
    a[i]++;
  }
  ans++;
  int hi = 0;
  vector<int> ids;
  REP(i, n) {
    if ((a[i] & -a[i]) > hi) {
      hi = a[i] & -a[i];
      ids = {i};
    } else if ((a[i] & -a[i]) == hi) ids.eb(i);
  }
  assert(size(ids) >= 2);
  a[ids[0]]--;
  a[ids[1]]++;
  print();
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}