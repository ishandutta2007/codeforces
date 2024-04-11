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

const int maxn = 3123;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int f[maxn][maxn], n, m;
char s[maxn], t[maxn];

int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  REP(j, n + 1) f[0][j] = 1;
  int ans = 0;
  FOR(i, 1, n) REP(j, n - i + 1) {
    if (j != n) {
      if (j >= m || s[i] == t[j + 1]) f[i][j] = add(f[i][j], f[i - 1][j + 1]);
    }
    if (i + j > m || s[i] == t[i + j]) f[i][j] = add(f[i][j], f[i - 1][j]);
    if (j == 0 && i >= m) ans = add(ans, f[i][j]);
  }
  printf("%d", ans);
}