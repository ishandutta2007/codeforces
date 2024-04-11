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

const int MOD = 998244353;
const int maxn = 1123456;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, cnt[maxn], inv[maxn];
vector<int> G[maxn];

int main() {
  inv[1] = 1;
  FOR(i, 2, 1e6) inv[i] = mul(MOD - MOD / i, inv[MOD % i]);
  scanf("%d", &n);
  FOR(i, 1, n) {
    int k; scanf("%d", &k);
    G[i].resize(k);
    for (auto &x : G[i]) {
      scanf("%d", &x);
      cnt[x]++;
    }
  }
  int ans = 0;
  FOR(i, 1, n) for (auto j : G[i]) ans = add(ans, mul(mul(inv[n], inv[G[i].size()]), mul(cnt[j], inv[n])));
  printf("%d", ans);
}