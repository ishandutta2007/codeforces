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

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int dp[maxn], a[maxn], n, ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  dp[0] = 1;
  FOR(i, 1, n) {
    int upp = sqrt(a[i]) + 0.5;
    stack<int> s;
    FOR(j, 1, upp) if (a[i] % j == 0) {
      s.emplace(j);
      if (a[i] != j * j && a[i] <= n * j) dp[a[i] / j] = add(dp[a[i] / j], dp[a[i] / j - 1]);
    }
    while (!s.empty()) {
      auto j = s.top(); s.pop();
      dp[j] = add(dp[j], dp[j - 1]);
    }
  }
  FOR(i, 1, n) ans = add(ans, dp[i]);
  printf("%d", ans);
}