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

// 10^9 > MOD...WTF
inline int add(int a, int b) {
  return (a + b) % MOD;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, m;
int inv[maxn], d[maxn], s[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", d + i);
  sort(d + 1, d + n + 1);
  inv[0] = inv[1] = 1;
  FOR(i, 2, n + 1) inv[i] = mul(inv[MOD % i], MOD - MOD / i);
  FOR(i, 1, n) s[i] = add(s[i - 1], d[i]);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int i = lower_bound(d + 1, d + n + 1, b) - d;
    int big = n - i + 1, ans = 0;
    if (big >= a)
      ans = add(mul(mul(big - a, inv[big]), add(s[n], MOD - s[n - big])), mul(mul(big - a + 1, inv[big + 1]), s[n - big]));
    printf("%d\n", ans);
  }
}