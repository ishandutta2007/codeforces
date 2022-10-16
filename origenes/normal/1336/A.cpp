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

int n, k;
int dep[maxn], sz[maxn], id[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  sz[u] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  iota(id + 1, id + n + 1, 1);
  nth_element(id + 1, id + k + 1, id + n + 1, [&](int a, int b) {return dep[a] - sz[a] > dep[b] - sz[b]; });
  ll ans = 0;
  FOR(i, 1, k) ans += dep[id[i]] - sz[id[i]];
  printf("%lld", ans);
}