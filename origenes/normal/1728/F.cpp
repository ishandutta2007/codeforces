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

const int maxn = 1123;

int a[maxn], match[maxn];
bool vis[maxn * maxn];
vector<int> G[maxn * maxn];

bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = true;
  for (auto v : G[u]) if (match[v] == -1 || dfs(match[v])) {
    match[v] = u;
    return true;
  }
  return false;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  vector<ll> w;
  FOR(i, 1, n) {
    cin >> a[i];
    FOR(j, 1, n) w.eb(ll(a[i]) * j);
  }
  sort(all(w));
  uni(w);
  FOR(i, 1, n) FOR(j, 1, n) G[lower_bound(all(w), ll(a[i]) * j) - w.begin()].eb(i);
  reset(match, -1);
  ll ans = 0;
  REP(i, size(w)) if (dfs(i)) {
    ans += w[i];
    reset(vis, 0);
  }
  cout << ans << '\n';
}