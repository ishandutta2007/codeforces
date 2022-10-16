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

const int maxn = 112345;

int n, m;
int a[maxn];
bool vis[maxn];
vector<int> G[maxn], adj[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, m) cin >> a[i];
  ll ans = 0;
  FOR(i, 1, m) {
    G[a[i]].eb(i);
    if (i > 1 && a[i - 1] != a[i]) adj[a[i]].eb(a[i - 1]);
    if (i < m && a[i + 1] != a[i]) adj[a[i]].eb(a[i + 1]);
    if (i > 1) ans += abs(a[i] - a[i - 1]);
  }
  if (!ans) {
    cout << ans;
    return 0;
  }
  ll pre = ans;
  FOR(i, 1, n) sort(all(adj[i]));
  FOR(i, 1, m) if (!vis[a[i]]) {
    vis[a[i]] = true;
    ll now = pre;
    for (auto j : G[a[i]]) {
      if (j > 1) now -= abs(a[j] - a[j - 1]);
      if (j < m) now -= abs(a[j] - a[j + 1]);
    }
    int best = adj[a[i]][adj[a[i]].size() / 2];
    for (auto j : G[a[i]]) {
      if (j > 1 && a[j - 1] != a[i]) now += abs(best - a[j - 1]);
      if (j < m && a[j + 1] != a[i]) now += abs(best - a[j + 1]);
    }
    chkmin(ans, now);
  }
  cout << ans;
}