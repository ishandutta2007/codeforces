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
  int n; cin >> n;
  vector<string> s(3);
  REP(i, 3) cin >> s[i];
  atcoder::dsu dsu(3 * n);
  vector<int> hcnt(n), vcnt(n), cnt(n), nex(n);
  REP(i, n) {
    if (i) {
      hcnt[i] = hcnt[i - 1];
      vcnt[i] = vcnt[i - 1];
      cnt[i] = cnt[i - 1];
    }
    if (s[0][i] == '1' && s[1][i] == '1') {
      vcnt[i] += !dsu.same(i, n + i);
      dsu.merge(i, n + i);
    }
    if (s[1][i] == '1' && s[2][i] == '1') {
      vcnt[i] += !dsu.same(n + i, 2 * n + i);
      dsu.merge(n + i, 2 * n + i);
    }
    if (i) REP(j, 3) if (s[j][i] == '1' && s[j][i - 1] == '1') {
      hcnt[i] += !dsu.same(j * n + i - 1, i + j * n);
      dsu.merge(j * n + i - 1, i + j * n);
    }
    REP(j, 3) cnt[i] += s[j][i] == '1';
  }
  ROF(i, n - 1, 0) if (s[0][i] == '1' && s[1][i] == '0' && s[2][i] == '1') {
    if (i == n - 1 || !nex[i + 1]) nex[i] = i;
    else nex[i] = nex[i + 1];
  }
  int q; cin >> q;
  while (q--) {
    int l, r, add = 0, ans;
    cin >> l >> r;
    l--, r--;
    if (nex[l]) {
      l = nex[l] + 1;
      if (l > r) add = 2;
      else if (s[0][l] == '0' && s[2][l] == '0') add = 2;
      else if (s[0][l] == '0' || s[1][l] == '0' || s[2][l] == '0') add = 1;
    }
    if (l) ans = max(0, cnt[r] - cnt[l - 1]) - max(0, vcnt[r] - vcnt[l - 1]);
    else ans = cnt[r] - vcnt[r];
    ans += add - max(0, hcnt[r] - hcnt[l]);
    cout << ans << '\n';
  }
}