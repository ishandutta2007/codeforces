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

int n, m, k, f[maxn], p[maxn];
vector<int> G[maxn], T[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    T[v].eb(u);
  }
  scanf("%d", &k);
  FOR(i, 1, k) scanf("%d", p + i);
  int source = p[1], sink = p[k];
  reset(f, 0x3f);
  f[sink] = 0;
  queue<int> q;
  q.emplace(sink);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : T[u]) if (f[v] > f[u] + 1) {
      f[v] = f[u] + 1;
      q.emplace(v);
    }
  }
  int mn = 0, mx = 0;
  FOR(i, 2, k) if (f[p[i]] != f[p[i - 1]] - 1) mn++;
  FOR(i, 1, k - 1) {
    int u = p[i], cnt = 0;
    for (auto v : G[u]) if (f[v] == f[u] - 1) cnt++;
    if (f[p[i + 1]] == f[u] - 1) cnt--;
    if (cnt) mx++;
  }
  printf("%d %d", mn, mx);
}