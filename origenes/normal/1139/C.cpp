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

const int maxn = 112345;
const int MOD = 1e9 + 7;

vector<int> G[maxn];
int n, k, sz, ans;
bool vis[maxn];

void dfs(int u) {
  vis[u] = true;
  sz++;
  for (int v : G[u]) if (!vis[v]) dfs(v);
}

inline int add(int a, int b) {
  return (a + b) % MOD;
}

int pow_mod(int b, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = ll(ret) * b % MOD;
    b = ll(b) * b % MOD;
    pw >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    if (c == 0) {
      G[u].eb(v);
      G[v].eb(u);
    }
  }
  FOR(i, 1, n) if (!vis[i]) {
    sz = 0;
    dfs(i);
    ans = add(ans, MOD - pow_mod(sz, k));
  }
  ans = add(ans, pow_mod(n, k));
  printf("%d", ans);
}