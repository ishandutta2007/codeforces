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
const int maxs = 112345;
const int maxt = 1123456;

char s[maxs], t[maxt];
int n, m, pref[maxt], pw[maxt], ipw[maxt];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int inv(int x) {
  int ret = 1, pw = MOD - 2;
  while (pw) {
    if (pw & 1) ret = mul(ret, x);
    x = mul(x, x);
    pw >>= 1;
  }
  return ret;
}

inline int get(int l, int r) {
  int ret = add(pref[r], MOD - pref[l - 1]);
  ret = mul(ret, ipw[l - 1]);
  return ret;
}

int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  pw[0] = 1;
  FOR(i, 1, m) pw[i] = mul(pw[i - 1], 27);
  int iv = inv(27);
  ipw[0] = 1;
  FOR(i, 1, m) ipw[i] = mul(ipw[i - 1], iv);
  if (s[1] == '1') {
    FOR(i, 1, n) s[i] = s[i] == '1' ? '0' : '1';
  }
  int zero = 0, one = 0;
  FOR(i, 1, n) {
    if (s[i] == '0') zero++;
    else one++;
  }
  FOR(i, 1, m) pref[i] = add(mul(t[i] - 'a' + 1, pw[i - 1]), pref[i - 1]);
  int ans = 0;
  for (int l0 = 1; l0 * zero <= m; l0++) {
    if ((m - l0 * zero) % one) continue;
    int l1 = (m - l0 * zero) / one;
    if (l1 <= 0) break;
    int h0 = -1, h1 = -1, off = 1;
    bool no = false;
    FOR(i, 1, n) {
      if (s[i] == '0') {
        if (off + l0 - 1 > m) {
          no = true;
          break;
        }
        if (h0 < 0) h0 = get(off, off + l0 - 1);
        else if (h0 != get(off, off + l0 - 1)) {
          no = true;
          break;
        }
        off += l0;
      } else {
        if (off + l1 - 1 > m) {
          no = true;
          break;
        }
        if (h1 < 0) h1 = get(off, off + l1 - 1);
        else if (h1 != get(off, off + l1 - 1)) {
          no = true;
          break;
        }
        off += l1;
      }
    }
    if (!no && h0 != h1) ans++;
  }
  printf("%d", ans);
}