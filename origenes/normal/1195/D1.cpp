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

const int maxn = 112345;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, ans;
int cnt[15], a[maxn][15], bit[maxn], pw[30];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", &a[i][14]);
    REP(j, 11) {
      a[i][j] = a[i][14] % 10;
      a[i][14] /= 10;
      if (!a[i][14]) {
        bit[i] = j + 1;
        break;
      }
    }
    cnt[bit[i]]++;
  }
  pw[0] = 1;
  FOR(i, 1, 25) pw[i] = mul(pw[i - 1], 10);
  FOR(i, 1, n) {
    FOR(j, 1, 10) {
      if (j >= bit[i] - 1) {
        REP(k, bit[i]) ans = add(ans, mul(mul(a[i][k], pw[k * 2]), cnt[j]));
      } else {
        REP(k, j + 1) ans = add(ans, mul(mul(a[i][k], pw[k * 2]), cnt[j]));
        FOR(k, j + 1, bit[i] - 1) ans = add(ans, mul(mul(a[i][k], pw[j * 2 + k - j]), cnt[j]));
      }
      if (j >= bit[i]) {
        REP(k, bit[i]) ans = add(ans, mul(mul(a[i][k], pw[k * 2 + 1]), cnt[j]));
      } else {
        REP(k, j) ans = add(ans, mul(mul(a[i][k], pw[k * 2 + 1]), cnt[j]));
        FOR(k, j, bit[i] - 1) ans = add(ans, mul(mul(a[i][k], pw[j * 2 + k - j]), cnt[j]));
      }
    }
  }
  printf("%d", ans);
}