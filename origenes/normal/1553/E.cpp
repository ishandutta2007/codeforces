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
  int n, m; cin >> n >> m;
  vector<int> p(n);
  vector<int> cnt(n);
  REP(i, n) {
    cin >> p[i];
    p[i]--;
    cnt[(i - p[i] + n) % n]++;
  }
  vector<int> ans;
  REP(k, n) if (cnt[k] >= n / 3) {
    vector<int> q(n);
    REP(i, n) q[(i - k + n) % n] = p[i];
    vector<bool> vis(n);
    int need = 0;
    REP(i, n) if (!vis[i]) {
      vis[i] = true;
      for (int j = q[i]; j != i; j = q[j]) {
        vis[j] = true;
        need++;
      }
    }
    if (need <= m) ans.eb(k);
  }
  cout << ans.size();
  for (auto k : ans) cout << ' ' << k;
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}