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

int d[2 * maxn], n;
ll s[2 * maxn], x, val[maxn * 5], f[maxn * 2];

int main() {
  scanf("%d%lld", &n, &x);
  FOR(i, 1, n) scanf("%d", d + i);
  FOR(i, 1, n) d[i + n] = d[i];
  FOR(i, 1, 2 * n) s[i] = s[i - 1] + d[i];
  FOR(i, 1, 1e6) val[i] = val[i - 1] + i;
  FOR(i, 1, 2 * n) f[i] = f[i - 1] + val[d[i]];
  int st = 1, j = 1;
  while (s[st] < x) st++;
  ll ans = 0;
  FOR(i, st, 2 * n) {
    while (s[i] - s[j] > x) j++;
    ll now = f[i] - f[j];
    int rem = x - s[i] + s[j];
    now += val[d[j]] - val[d[j] - rem];
    chkmax(ans, now);
  }
  printf("%lld", ans);
}