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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  REP(i, k) cin >> a[i];
  auto check = [&a](int n, int m) {
    bool extra = false;
    ll tot = 0;
    for (auto x : a) {
      if (x / n > 2) extra = true;
      if (x / n >= 2) tot += x / n;
    }
    return tot >= m && (extra || m % 2 == 0);
  };
  if (check(n, m) || check(m, n)) cout << "Yes\n";
  else cout << "No\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}