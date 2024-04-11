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
const int MOD = 998244353;

int n, p10[maxn];

int main() {
  scanf("%d", &n);
  p10[0] = 1;
  FOR(i, 1, n) p10[i] = ll(p10[i - 1]) * 10 % MOD;
  FOR(i, 1, n - 1) {
    ll ans = 20LL * 9 * p10[n - i - 1] % MOD;
    ans += (n - i - 1) * 10LL * 81 * p10[n - i - 2] % MOD;
    printf("%lld ", ans % MOD);
  }
  printf("10");
}