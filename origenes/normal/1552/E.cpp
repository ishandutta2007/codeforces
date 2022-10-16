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

const int maxn = 112;

vector<tuple<int, int, int, int>> intervals[maxn];
vector<int> G[maxn];
bool vis[maxn];
pii ans[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k;
  cin >> n >> k;
  vector<int> c(n * k);
  REP(i, n * k) {
    cin >> c[i];
    G[c[i]].eb(i);
  }
  FOR(i, 1, n) FOR(j, 1, k - 1) intervals[j].eb(G[i][j], G[i][j - 1], i, j);
  int mx = (n + k - 2) / (k - 1);
  FOR(i, 1, k - 1) {
    sort(all(intervals[i]));
    int to = mx;
    REP(j, n) {
      auto [r, l, col, id] = intervals[i][j];
      if (vis[col]) continue;
      vis[col] = true;
      ans[col] = {l + 1, r + 1};
      if (!--to) break;
    }
  }
  FOR(i, 1, n) cout << ans[i]._1 << ' ' << ans[i]._2 << '\n';
}