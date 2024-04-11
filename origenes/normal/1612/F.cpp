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
  int n, m, q;
  cin >> n >> m >> q;
  set<pii> bonus;
  while (q--) {
    int x, y;
    cin >> x >> y;
    bonus.emplace(x, y);
  }
  int ans = 0;
  vector<pii> now; now.eb(1, 1);
  while (now[0] != mp(n, m)) {
    vector<pii> tmp;
    for (auto [x, y] : now) {
      int reach = x + y + bonus.count(mp(x, y));
      tmp.eb(min(reach, n), y);
      tmp.eb(x, min(reach, m));
    }
    sort(all(tmp), greater<>());
    int mx = 0;
    now.clear();
    for (auto [x, y] : tmp) {
      if (y <= mx) continue;
      chkmax(mx, y);
      now.eb(x, y);
    }
    ans++;
  }
  cout << ans;
}