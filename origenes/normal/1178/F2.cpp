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

const int maxn = 1123;
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
int L[maxn], R[maxn], f[maxn][maxn], g[maxn][maxn];
vector<int> c;

int dfs(int l, int r) {
  if (l > r) return 1;
  if (f[l][r] != -1) return f[l][r];
  int &ret = f[l][r];
  ret = 0;
  int colour = g[l][r];
  int x = L[colour], y = R[colour], sum[3] = {};
  sum[1] = 1;
  int pre = x + 1;
  FOR(i, x + 1, y) if (c[i] == colour) {
    sum[1] = mul(sum[1], dfs(pre, i - 1));
    pre = i + 1;
  }
  int now = x;
  ROF(i, x, l) {
    chkmin(now, L[c[i]]);
    if (now >= i) sum[0] = add(sum[0], mul(dfs(l, i - 1), dfs(i, x - 1)));
  }
  now = y;
  FOR(i, y, r) {
    chkmax(now, R[c[i]]);
    if (now <= i) sum[2] = add(sum[2], mul(dfs(y + 1, i), dfs(i + 1, r)));
  }
  return ret = mul(mul(sum[0], sum[1]), sum[2]);
}

int main() {
  scanf("%d%d", &n, &m);
  c.resize(m);
  for (auto &x : c) scanf("%d", &x);
  uni(c);
  m = c.size();
  if (m > 2 * n) {
    puts("0");
    return 0;
  }
  REP(i, m) R[c[i]] = i;
  ROF(i, m - 1, 0) L[c[i]] = i;
  REP(i, m) {
    g[i][i] = c[i];
    FOR(j, i + 1, m - 1) g[i][j] = min(g[i][j - 1], c[j]);
  }
  reset(f, -1);
  printf("%d", dfs(0, m - 1));
}