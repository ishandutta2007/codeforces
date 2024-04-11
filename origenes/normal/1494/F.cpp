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

const int maxn = 3123;

int n, m;
int G[maxn][maxn];
int deg[maxn];
vector<int> ans;

void euler(int st) {
  stack<int> s;
  s.emplace(st);
  while (!s.empty()) {
    auto u = s.top();
    bool found = false;
    FOR(v, 1, n) if (G[u][v] > 0) {
        G[u][v]--, G[v][u]--;
        s.emplace(v);
        found = true;
        break;
      }
    if (!found) {
      ans.eb(u);
      s.pop();
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, m) {
    int u, v; cin >> u >> v;
    G[u][v]++;
    G[v][u]++;
    deg[u]++; deg[v]++;
  }
  int odd = 0;
  FOR(i, 1, n) if (deg[i] % 2 == 1) odd++;
  if (odd == 0 || odd == 2) {
    int st = 1;
    FOR(i, 1, n) if (deg[i] % 2 == 1) {
        st = i;
        break;
      }
    euler(st);
    cout << ans.size();
    for (auto x : ans) cout << ' ' << x;
    return 0;
  }
  FOR(i, 1, n) if (deg[i] > 2) {
      vector<int> skip(n + 1);
      FOR(j, 1, n) if (G[i][j] && deg[j] % 2 == 1) {
          deg[j]--, deg[i]--;
          G[i][j] = G[j][i] = 0;
          skip[j] = 1;
        }
      odd = 0;
      FOR(j, 1, n) if (deg[j] % 2 == 1) odd++;
      queue<int> q;
      vector<int> vis(n + 1);
      reborn:
      FOR(j, 1, n) if (deg[j]) {
        vis[j] = 1;
        q.emplace(j);
        break;
      }
      while (!q.empty()) {
        auto u = q.front(); q.pop();
        FOR(v, 1, n) if (!vis[v] && deg[v] && G[u][v]) {
          q.emplace(v);
          vis[v] = 1;
        }
      }
      FOR(j, 1, n) if (!vis[j] && deg[j]) {
        if (deg[i] % 2 == 0 && odd == 0) {
          FOR(k, 1, n) if (skip[k] && !vis[k] && deg[k]) {
            G[i][k] = G[k][i] = 1;
            odd = 2;
            deg[i]++, deg[k]++;
            FOR(x, 1, n) vis[x] = 0;
            skip[k] = 0;
            goto reborn;
          }
        }
        goto label;
      }
      if (deg[i] % 2 == 0 && odd == 2) {
        bool found = false;
        FOR(j, 1, n) if (skip[j] && vis[j] && deg[j] % 2 == 1) {
          G[i][j] = G[j][i] = 1;
          skip[j] = 0;
          deg[j]++, deg[i]++;
          found = true;
          break;
        }
        if (!found) goto label;
      }
      if (odd && odd != 2) {
        label:
        FOR(j, 1, n) if (skip[j]) {
            deg[i]++, deg[j]++;
            G[i][j] = G[j][i] = 1;
          }
        continue;
      }
      if (deg[i] % 2 == 0 && odd == 0) {
        FOR(j, 1, n) if (skip[j] && vis[j]) {
          G[i][j] = G[j][i] = 1;
          skip[j] = 0;
          deg[i]++, deg[j]++;
          break;
        }
      }
      int st = i;
      euler(st);
      ans.eb(-1);
      FOR(j, 1, n) if (skip[j]) {
          ans.eb(j);
          ans.eb(i);
        }
      cout << ans.size();
      for (auto x : ans) cout << ' ' << x;
      return 0;
    }
  cout << 0;
}
/*
10 10
1 2
2 3
3 4
4 5
5 6
6 7
7 2
6 8
6 9
6 10

 9 9
 1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 7 2
 7 8
 7 9
 */