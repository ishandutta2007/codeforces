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
  set<int> pending;
  map<int, int> active;
  REP(i, n + 2) pending.emplace(i);
  while (q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      if (x == 0) {
        for (auto it = pending.lower_bound(l); *it <= r; it = pending.lower_bound(l)) pending.erase(it);
      } else {
        auto it = active.lower_bound(l);
        if (it != active.end() && it->_2 <= r) continue;
        active[l] = r;
        it = active.find(l);
        while (it != active.begin() && prev(it)->_2 >= r) active.erase(prev(it));
      }
    } else {
      int x; cin >> x;
      if (!pending.count(x)) {
        cout << "NO\n";
        continue;
      }
      auto it = pending.find(x);
      int l = *prev(it), r = *next(it);
      auto it2 = active.upper_bound(l);
      if (it2 != active.end() && it2->_1 <= x && it2->_2 < r) cout << "YES\n";
      else cout << "N/A\n";
    }
  }
}