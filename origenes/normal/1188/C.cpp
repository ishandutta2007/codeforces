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
const int maxa = 112345;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int f[maxa], a[maxn], g[maxn][maxn], s[maxn];
int n, K, ans;

int main() {
  scanf("%d%d", &n, &K);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  FOR(x, 0, 1e5) if (x <= 1 || a[n] - a[1] >= x * ll(K - 1)) {
    fill(s, s + K, 0);
    int l = 0;
    FOR(i, 1, n) {
      g[i][1] = 1;
      while (l + 1 < i && a[l + 1] + x <= a[i]) {
        l++;
        FOR(j, 1, K - 1) s[j] = add(s[j], g[l][j]);
      }
      FOR(j, 2, K) g[i][j] = s[j - 1];
      f[x] = add(f[x], g[i][K]);
    }
  }
  FOR(x, 0, 1e5) ans = add(ans, mul(add(f[x], MOD - f[x + 1]), x));
  printf("%d", ans);
}