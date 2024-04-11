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

const int maxn = 412345;

int n, tot;
pii match[maxn];
map<pair<ll, ll>, int> mmap;
vector<pii> G[maxn], ans;
bool vis[maxn], used[maxn];

int prepare(ll x, ll y) {
  ll d = gcd(x, y);
  x /= d, y /= d;
  if (!mmap.count(mp(x, y))) mmap[mp(x, y)] = ++tot;
  return mmap[mp(x, y)];
}

void dfs(int u) {
  vis[u] = true;
  for (auto [v, id] : G[u]) if (!used[id]) {
    used[id] = true;
    if (!vis[v]) dfs(v);
    if (match[v]._1) {
      ans.eb(id, match[v]._2);
      match[v] = {0, 0};
    } else if (match[u]._1) {
      ans.eb(match[u]._2, id);
      match[u] = {0, 0};
    } else match[u] = {v, id};
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    int u = prepare((a + b) * d, b * c);
    int v = prepare(a * d, (c + d) * b);
    G[u].eb(v, i);
    G[v].eb(u, i);
  }
  FOR(i, 1, tot) if (!vis[i]) dfs(i);
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
}