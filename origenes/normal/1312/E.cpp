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

int n;
int a[maxn], f[maxn], g[maxn][maxn];

int dfs(int l, int r) {
  if (l == r) return g[l][r] = a[l];
  if (g[l][r]) return g[l][r];
  g[l][r] = -1;
  FOR(m, l, r - 1) {
    int L = dfs(l, m), R = dfs(m + 1, r);
    if (L > 0 && L == R) return g[l][r] = L + 1;
  }
  return g[l][r];
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  reset(f, 0x3f);
  f[0] = 0;
  FOR(i, 1, n) FOR(j, i, n) if (dfs(i, j) > 0) chkmin(f[j], f[i - 1] + 1);
  printf("%d", f[n]);
}