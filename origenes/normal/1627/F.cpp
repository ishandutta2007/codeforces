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
  int n, k; cin >> n >> k;
  vector<vector<int>> ch(k + 1, vector<int>(k)), cv(k, vector<int>(k + 1)), f(k + 1, vector<int>(k + 1, 1e9));
  REP(i, n) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    if (r1 == r2) {
      int c = max(c1, c2);
      cv[r1][c]++, cv[k - r1 - 1][k - c]++;
    } else {
      int r = max(r1, r2);
      ch[r][c1]++, ch[k - r][k - c1 - 1]++;
    }
  }
  set<tuple<int, int, int>> q;
  q.emplace(0, 0, 0);
  f[0][0] = 0;
  while (!q.empty()) {
    auto [d, r, c] = *q.begin();
    q.erase(q.begin());
    if (d > f[r][c]) continue;
    if (r > 0 && d + cv[r - 1][c] < f[r - 1][c]) {
      f[r - 1][c] = d + cv[r - 1][c];
      q.emplace(f[r - 1][c], r - 1, c);
    }
    if (r < k && d + cv[r][c] < f[r + 1][c]) {
      f[r + 1][c] = d + cv[r][c];
      q.emplace(f[r + 1][c], r + 1, c);
    }
    if (c > 0 && d + ch[r][c - 1] < f[r][c - 1]) {
      f[r][c - 1] = d + ch[r][c - 1];
      q.emplace(f[r][c - 1], r, c - 1);
    }
    if (c < k && d + ch[r][c] < f[r][c + 1]) {
      f[r][c + 1] = d + ch[r][c];
      q.emplace(f[r][c + 1], r, c + 1);
    }
  }
  cout << n - f[k / 2][k / 2] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}