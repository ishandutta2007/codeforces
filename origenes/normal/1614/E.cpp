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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  ordered_set<int> s;
  int OFF = 0, last = 0;
  while (n--) {
    int T, k;
    cin >> T >> k;
    if (T < OFF) OFF--;
    else {
      ll lo = 0, hi = 2e9;
      while (lo < hi) {
        ll mi = lo + hi + 1 >> 1, now = OFF + mi - s.order_of_key(mi + 1);
        if (now <= T) lo = mi;
        else hi = mi - 1;
      }
      s.insert(lo + 1);
      lo = 0, hi = 2e9;
      while (lo < hi) {
        ll mi = lo + hi >> 1, now = OFF + mi - s.order_of_key(mi + 1);
        if (now >= T) hi = mi;
        else lo = mi + 1;
      }
      if (lo > 0) {
        s.insert(lo);
        OFF++;
      }
    }
    while (k--) {
      int x; cin >> x;
      x = (x + last) % int(1e9 + 1);
      last = OFF + x - s.order_of_key(x + 1);
      cout << last << '\n';
    }
  }
}