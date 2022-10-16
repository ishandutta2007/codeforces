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

const int maxn = 512345;

int n, m;
char ans[maxn];
int f[maxn];
vector<pii> G[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v, t;
    scanf("%d%d%d", &u, &v, &t);
    G[v].eb(u, t);
  }
  reset(f, -1);
  f[n] = 0;
  queue<int> q;
  q.emplace(n);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto [v, t] : G[u]) if (!~f[v]) {
      if (!ans[v]) ans[v] = 1 - t + '0';
      else if (ans[v] == t + '0') {
        f[v] = f[u] + 1;
        q.emplace(v);
      }
    }
  }
  printf("%d\n", f[1]);
  FOR(i, 1, n) if (!ans[i]) ans[i] = '0';
  puts(ans + 1);
}