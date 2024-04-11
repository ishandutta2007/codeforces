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
  int n, c;
  cin >> n >> c;
  vector<int> vis(c + 1), s(c + 1);
  while (n--) {
    int x; cin >> x;
    vis[x]++;
  }
  FOR(i, 1, c) s[i] = s[i - 1] + vis[i];
  FOR(i, 1, c) if (vis[i]) {
    for (int j = 1; i * j <= c; j++) {
      int mx = min(c, i * j + i - 1);
      if (s[mx] - s[i * j - 1] > 0 && !vis[j]) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}