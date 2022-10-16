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

int n, l[maxn], r[maxn], f[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  f[u] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    f[u] += f[v];
  }
}

void dfs(int u, int par, int off) {
  int ch = G[u].size() - (u > 1);
  r[u] = off + ch;
  int L = r[u], R = r[u] + 1;
  for (auto v : G[u]) if (v != par) {
    l[v] = --L;
    dfs(v, u, R);
    R += 2 * f[v] - 1;
  }
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  l[1] = 1;
  dfs(1, 0, 2);
  FOR(i, 1, n) printf("%d %d\n", l[i], r[i]);
}