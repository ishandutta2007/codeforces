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

void solve() {
  int n;
  cin >> n;
  vector<int> need;
  REP(i, n) {
    int x; cin >> x;
    if (x) need.eb(abs(x));
  }
  sort(all(need)); uni(need);
  vector<int> d;
  if (need.size() < n) {
    cout << "YES\n";
    return;
  }
  int ALL = 1;
  REP(i, n) ALL *= 3;
  FOR(mask, 1, ALL - 1) {
    int now = mask, s = 0;
    REP(i, n) {
      if (now % 3 == 1) s += need[i];
      else if (now % 3 == 2) s -= need[i];
      now /= 3;
    }
    if (s == 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}