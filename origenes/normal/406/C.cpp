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

bool vis[maxn];
int n, m;
vector<pii> G[maxn];

int dfs(int u) {
  vector<int> childs;
  for (auto [v, i] : G[u]) if (!vis[i]) {
    vis[i] = true;
    childs.eb(v);
  }
  stack<pii> s;
  for (auto v : childs) {
    int w = dfs(v);
    if (w) cout << u << ' ' << v << ' ' << w << '\n';
    else s.emplace(u, v);
  }
  while (s.size() >= 2) {
    int v1 = s.top()._2; s.pop();
    int v2 = s.top()._2; s.pop();
    cout << v1 << ' ' << u << ' ' << v2 << '\n';
  }
  return s.empty() ? 0 : s.top()._2;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  if (m % 2 == 1) {
    cout << "No solution";
    return 0;
  }
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v, i);
    G[v].eb(u, i);
  }
  dfs(1);
}