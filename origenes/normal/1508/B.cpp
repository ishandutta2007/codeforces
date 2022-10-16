#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

ll f[65];

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  int off = max(n - 61, 0);
  n -= off;
  if (f[n] < k) {
    cout << -1 << '\n';
    return;
  }
  vector<int> ans(off);
  iota(all(ans), 1);
  ordered_set<int> s;
  FOR(i, off + 1, off + n) s.insert(i);
  ROF(i, n - 1, 0) {
    ll acc = 0;
    ROF(j, i, 0) {
      if (k <= acc + f[j]) {
        int v = *s.find_by_order(i - j);
        ans.eb(v);
        k -= acc;
        s.erase(v);
        if (j != i) {
          FOR(x, j + 1, i) {
            v = *s.find_by_order(i - x);
            ans.eb(v);
            s.erase(v);
          }
        }
        i -= i - j;
        break;
      }
      acc += f[j];
    }
  }
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  f[0] = 1;
  ll s = 1;
  FOR(i, 1, 61) {
    f[i] = s;
    s += f[i];
  }
  int T; cin >> T;
  while (T--) solve();
}