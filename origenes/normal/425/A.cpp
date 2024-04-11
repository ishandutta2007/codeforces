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

const int maxn = 212;

int n, k;
int a[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> a[i];
  int ans = -1000;
  FOR(l, 1, n) {
    set<pii> in, out;
    FOR(i, 1, n) out.emplace(a[i], i);
    int now = 0;
    FOR(r, l, n) {
      in.emplace(a[r], r);
      out.erase(mp(a[r], r));
      now += a[r];
      auto it = out.rbegin();
      int cnt = 0, inc = 0;
      chkmax(ans, now);
      for (auto [x, _] : in) {
        cnt++;
        if (it == out.rend() || cnt > k || x >= it->_1) break;
        inc += it->_1 - x;
        chkmax(ans, now + inc);
        it++;
      }
    }
  }
  cout << ans;
}