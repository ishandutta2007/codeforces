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
const int maxa = 1123456;
const int MOD = 1e9 + 7;

int a[maxn], cnt[maxa], dp[maxa], pw[maxa];
int n;

inline int add(int a, int b) {
  a += b;
  return a >= MOD ? a - MOD : a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int main() {
  scanf("%d", &n);
  int mmax = 0;
  FOR(i, 1, n) {
    scanf("%d", a + i);
    chkmax(mmax, a[i]);
    int upp = sqrt(a[i]) + 0.5;
    FOR(j, 2, upp) if (a[i] % j == 0) {
        cnt[j]++;
        if (a[i] / j != j) cnt[a[i] / j]++;
      }
    cnt[a[i]]++;
  }
  pw[0] = 1;
  FOR(i, 1, 1e6) pw[i] = add(pw[i - 1], pw[i - 1]);
  int ans = 0;
  ROF(i, mmax, 2) if (cnt[i]) {
      int ex = 0;
      for (int j = 2 * i; j <= mmax; j += i) ex = add(ex, dp[j]);
      dp[i] = add(mul(cnt[i], pw[cnt[i] - 1]), MOD - ex);
      ans = add(ans, mul(dp[i], i));
    }
  printf("%d", ans);
}