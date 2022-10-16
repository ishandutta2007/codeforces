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
  string s; cin >> s;
  int cnt = 0;
  for (auto c : s) if (c == '1') cnt++;
  if (ll(cnt) * m % n) {
    cout << "-1\n";
    return;
  }
  int need = ll(cnt) * m / n;
  vector<int> pre(2 * n + 1);
  FOR(i, 1, 2 * n) {
    pre[i] = pre[i - 1];
    if (s[(i - 1) % n] == '1') pre[i]++;
    if (i >= m && pre[i] == pre[i - m] + need) {
      if (i <= n) {
        cout << "1\n";
        cout << i - m + 1 << ' ' << i << '\n';
      } else {
        cout << "2\n";
        cout << "1 " << i - n << '\n';
        cout << i - m + 1 << ' ' << n << '\n';
      }
      return;
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}