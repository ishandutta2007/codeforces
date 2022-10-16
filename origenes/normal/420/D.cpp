// e3c89998462e81ab5d0f2d6ba5a57fe7820f7a94e50885e6665add0087c7ba9d
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, T, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

const int maxn = 1123456;

//    ordered_set<int> s;
//    s.insert(1);
//    s.insert(3);
//    cout << s.order_of_key(2) << endl;
//    cout << *s.find_by_order(0) << endl;


int n, m;
int loc[maxn], a[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  ordered_set<int> s;
  int lo = m + 5, hi = m + 5;
  FOR(i, lo + 1, lo + n) s.insert(mp(i, 1));
  FOR(i, 1, m) {
    int x, y; cin >> x >> y;
    if (!loc[x]) {
      loc[x] = s.find_by_order(y - 1)->_1;
      if (loc[x] <= hi) {
        cout << -1;
        return 0;
      }
      a[loc[x] - hi] = x;
    }
    if (loc[x] != s.find_by_order(y - 1)->_1) {
      cout << -1;
      return 0;
    }
    s.erase(loc[x]);
    s.insert(mp(lo, 1));
    loc[x] = lo--;
  }
  int r = 1;
  FOR(i, 1, n) if (!loc[i]) {
      while (a[r]) r++;
      a[r] = i;
    }
  FOR(i, 1, n) cout << a[i] << ' ';
}