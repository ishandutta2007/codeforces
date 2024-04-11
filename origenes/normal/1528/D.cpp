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

const int maxn = 612;

int n, m;
ll ans[maxn][maxn];
vector<pair<int, ll>> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  REP(i, m) {
    int a, b, c; cin >> a >> b >> c;
    G[a].eb(b, c);
  }
  reset(ans, 0x3f);
  REP(i, n) {
    vector<bool> vis(n);
    for (auto [j, c] : G[i]) chkmin(ans[i][j], c);
    REP(j, n) {
      int best = -1;
      REP(k, n) if (!vis[k]) {
        if (best == -1 || ans[i][k] < ans[i][best]) best = k;
      }
      vis[best] = true;
      chkmin(ans[i][(best + 1) % n], ans[i][best] + 1);
      for (auto [to, c] : G[best]) {
        to = (to + ans[i][best]) % n;
        chkmin(ans[i][to], ans[i][best] + c);
      }
    }
    ans[i][i] = 0;
  }
  REP(i, n) {
    REP(j, n) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}