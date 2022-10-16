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

int n, m, k, f[maxn];
vector<int> G[maxn];
stack<int> s;

void dfs(int u, int par) {
  s.emplace(u);
  f[u] = f[par] + 1;
  int best = 0;
  for (auto v : G[u]) if (v != par) if (f[best] < f[v]) best = v;
  if (best) {
    if (f[u] - f[best] + 1 <= k) {
      printf("2\n%d\n", f[u] - f[best] + 1);
      int to = f[u] - f[best] + 1;
      while (to--) {
        printf("%d ", s.top());
        s.pop();
      }
    } else {
      puts("1");
      int req = (k + 1) / 2;
      while (req--) {
        printf("%d ", s.top());
        s.pop(); s.pop();
      }
    }
    exit(0);
  }
  for (auto v : G[u]) if (!f[v]) dfs(v, u);
  s.pop();
}

void bfs() {
  queue<int> q;
  reset(f, -1);
  f[1] = 0;
  q.emplace(1);
  int cnt[2] = {1, 0};
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : G[u]) if (f[v] == -1) {
      f[v] = 1 - f[u];
      q.emplace(v);
      cnt[f[v]]++;
    }
  }
  int c = cnt[0] >= (k + 1) / 2 ? 0 : 1;
  puts("1");
  int req = (k + 1) / 2;
  FOR(i, 1, n) if (f[i] == c) {
    printf("%d ", i);
    if (!--req) exit(0);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  if (m == n - 1) bfs();
  dfs(1, 0);
}