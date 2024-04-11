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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

vector<pii> G[maxn];
int deg[maxn], n, k, c[maxn], ans;

void dfs(int u, int par, int cc) {
  for (auto _ : G[u]) {
    int v = _._1, idx = _._2;
    if (v == par) continue;
    c[idx] = cc;
    cc++;
    if (cc == ans) cc = 0;
    dfs(v, u, cc);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v, i);
    G[v].eb(u, i);
    deg[u]++, deg[v]++;
  }
  nth_element(deg + 1, deg + k + 1, deg + n + 1, greater<>());
  ans = deg[k + 1];
  dfs(1, 0, 0);
  printf("%d\n", ans);
  REP(i, n - 1) printf("%d ", c[i] + 1);
}