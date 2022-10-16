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

bool eq[maxn][maxn][maxn];

void solve() {
  int n; cin >> n;
  REP(i, n) FOR(j, i + 1, n - 1) {
    string s; cin >> s;
    REP(k, n) eq[k][i][j] = eq[k][j][i] = (s[k] == '1');
  }
  FOR(i, 1, n - 1) {
    vector<vector<int>> G(n);
    G[0].eb(i); G[i].eb(0);
    vector<int> par(n, -1);
    par[i] = 0, par[0] = i;
    queue<int> q;
    q.emplace(0); q.emplace(i);
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      FOR(v, 1, n - 1) {
        if (par[v] != -1 || !eq[u][v][par[u]]) continue;
        q.emplace(v);
        par[v] = u;
        G[u].eb(v); G[v].eb(u);
      }
    }
    auto check = [n, &G]() {
      bool ok = true;
      REP(k, n) {
        if (!ok) break;
        vector<int> dep(n, -1);
        function<void(int, int, int)> dfs = [&](int u, int par, int d) {
          dep[u] = d;
          for (auto v : G[u]) if (v != par) dfs(v, u, d + 1);
        };
        dfs(k, -1, 0);
        REP(i, n) {
          if (!ok) break;
          if (dep[i] == -1) ok = false;
          FOR(j, i + 1, n - 1) if ((dep[i] == dep[j]) != eq[k][i][j]) {
            ok = false;
            break;
          }
        }
      }
      return ok;
    };
    if (check()) {
      cout << "Yes\n";
      REP(u, n) for (auto v : G[u]) if (u < v) cout << u + 1 << ' ' << v + 1 << '\n';
      return;
    }
  }
  cout << "No\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}