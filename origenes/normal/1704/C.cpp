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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  REP(i, m) {
    cin >> a[i];
    a[i]--;
  }
  if (m == 1) {
    cout << "2\n";
    return;
  }
  sort(all(a));
  vector<int> segs;
  REP(i, m) segs.eb((a[(i + 1) % m] - a[i] + n) % n - 1);
  sort(all(segs), greater<>());
  int ans = 0;
  REP(i, m) {
    if (segs[i] <= 4 * i) break;
    if (segs[i] == 4 * i + 1) ans++;
    else ans += segs[i] - 4 * i - 1;
  }
  cout << n - ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}