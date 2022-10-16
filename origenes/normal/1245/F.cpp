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

const int maxn = 35;

int pw[maxn], L[maxn], R[maxn];
ll f[maxn][2][2][2][2];

int main() {
  int T; scanf("%d", &T);
  REP(i, 31) pw[i] = 1 << i;
  while (T--) {
    int l, r; scanf("%d%d", &l, &r);
    reset(L, 0); reset(R, 0); reset(f, 0);
    f[31][0][0][0][0] = 1;
    REP(i, 31) L[i] = (l >> i) & 1, R[i] = (r >> i) & 1;
    ROF(i, 31, 1) REP(sa, 2) REP(la, 2) REP(sb, 2) REP(lb, 2) {
      int nxt = i - 1;
      REP(a, 2) REP(b, 2) {
        if (a && b) continue;
        if (!sa && a && !R[nxt]) continue;
        if (!sb && b && !R[nxt]) continue;
        if (!la && !a && L[nxt]) continue;
        if (!lb && !b && L[nxt]) continue;
        if (!a && !b) {
          bool nsa = sa | R[nxt], nsb = sb | R[nxt];
          f[nxt][nsa][la][nsb][lb] += f[i][sa][la][sb][lb];
        } else if (a) {
          bool nsb = sb | R[nxt], nla = la | (!L[nxt]);
          f[nxt][sa][nla][nsb][lb] += f[i][sa][la][sb][lb];
        } else {
          bool nsa = sa | R[nxt], nlb = lb | (!L[nxt]);
          f[nxt][nsa][la][sb][nlb] += f[i][sa][la][sb][lb];
        }
      }
    }
    ll ans = 0;
    REP(sa, 2) REP(la, 2) REP(sb, 2) REP(lb, 2) ans += f[0][sa][la][sb][lb];
    printf("%lld\n", ans);
  }
}