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

const int maxn = 312345;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

inline bool cmp1(pii a, pii b) {
  return a._1 < b._1;
}

inline bool cmp2(pii a, pii b) {
  return a._2 < b._2;
}

int n, fac[maxn], ans;
pii a[maxn];

int main() {
  scanf("%d", &n);
  fac[0] = 1;
  FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
  FOR(i, 1, n) scanf("%d%d", &a[i]._1, &a[i]._2);
  ans = fac[n];
  sort(a + 1, a + n + 1, cmp1);
  int j = 1, now = 1;
  for (int i = 1; i <= n; ) {
    while (i <= n && a[i]._1 == a[j]._1) i++;
    now = mul(now, fac[i - j]);
    j = i;
  }
  ans = add(ans, MOD - now);
  sort(a + 1, a + n + 1, cmp2);
  j = 1, now = 1;
  for (int i = 1; i <= n; ) {
    while (i <= n && a[i]._2 == a[j]._2) i++;
    now = mul(now, fac[i - j]);
    j = i;
  }
  ans = add(ans, MOD - now);
  sort(a + 1, a + n + 1);
  j = 1, now = 1;
  for (int i = 1; i <= n; i++) {
    while (i <= n && a[i] == a[j]) i++;
    if (a[i]._1 > a[j]._1 && a[i]._2 < a[j]._2) now = 0;
    now = mul(now, fac[i - j]);
    j = i;
  }
  ans = add(ans, now);
  printf("%d", ans);
}