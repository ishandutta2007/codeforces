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

const int maxn = 512;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, m;
int c[maxn], f[maxn][maxn], pos[maxn], g[maxn][maxn];

int dfs(int l, int r) {
  if (l >= r) return 1;
  if (f[l][r] != -1) return f[l][r];
  int &ret = f[l][r];
  ret = 0;
  int br = pos[g[l][r]];
  int s = 0;
  FOR(i, br, r) s = add(s, mul(dfs(br + 1, i), dfs(i + 1, r)));
  FOR(i, l, br) ret = add(ret, mul(s, mul(dfs(l, i - 1), dfs(i, br - 1))));
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    scanf("%d", c + i);
    pos[c[i]] = i;
  }
  FOR(i, 1, n) {
    g[i][i] = c[i];
    FOR(j, i + 1, n) g[i][j] = min(g[i][j - 1], c[j]);
  }
  reset(f, -1);
  printf("%d", dfs(1, n));
}