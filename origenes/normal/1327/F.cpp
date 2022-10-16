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

const int maxn = 512345;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, m, k;
int l[maxn], r[maxn], x[maxn];

int main() {
  scanf("%d%d%d", &n, &k, &m);
  FOR(i, 1, m) scanf("%d%d%d", l + i, r + i, x + i);
  int ans = 1;
  REP(b, k) {
    vector<int> f(n + 1), s(n + 1), last(n + 2), one(n + 2);
    FOR(i, 1, m) {
      if (x[i] & (1 << b)) {
        one[l[i]]++;
        one[r[i] + 1]--;
      } else chkmax(last[r[i] + 1], l[i]);
    }
    f[0] = s[0] = 1;
    int cur = 0;
    FOR(i, 1, n) {
      cur += one[i];
      chkmax(last[i], last[i - 1]);
      if (cur) {
        f[i] = 0;
        s[i] = s[i - 1];
      } else {
        if (last[i]) f[i] = add(s[i - 1], MOD - s[last[i] - 1]);
        else f[i] = s[i - 1];
        s[i] = add(s[i - 1], f[i]);
      }
    }
    int now = 0;
    chkmax(last[n + 1], last[n]);
    FOR(i, last[n + 1], n) now = add(now, f[i]);
    ans = mul(ans, now);
  }
  printf("%d", ans);
}