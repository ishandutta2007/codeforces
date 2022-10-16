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

const int maxn = 212345;

int n;
ll ans = 0;
int h[maxn];
vector<int> G[maxn];

int dfs(int u, int par) {
  int mx[2] = {};
  for (auto v : G[u]) if (v != par) {
    int now = dfs(v, u);
    if (now > mx[0]) mx[1] = mx[0], mx[0] = now;
    else if (now > mx[1]) mx[1] = now;
  }
  if (par != 0) ans += max(h[u] - mx[0], 0);
  else ans += h[u] - mx[0] + h[u] - mx[1];
  return max(h[u], mx[0]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> h[i];
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  int r = max_element(h + 1, h + n + 1) - h;
  dfs(r, 0);
  cout << ans;
}