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

const int MOD = 998244353;
const int maxn = 212345;

int deg[maxn], fac[maxn];
int n, ans = 1;

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int main() {
  scanf("%d", &n);
  fac[0] = 1;
  FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
  FOR(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  FOR(i, 1, n) ans = mul(ans, fac[deg[i]]);
  printf("%d", mul(ans, n));
}