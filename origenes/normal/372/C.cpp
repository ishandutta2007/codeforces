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

const int maxn = 151234;
const int maxm = 312;

ll f[2][maxn];
int b[maxm], t[maxm], a[maxm], n, m, d;

int main() {
  scanf("%d%d%d", &n, &m, &d);
  FOR(i, 1, m) scanf("%d%d%d", a + i, b + i, t + i);
  FOR(i, 1, n) f[1][i] = abs(a[1] - i);
  FOR(i, 2, m) {
    int now = i & 1, pre = 1 - now;
    reset(f[now], 0x3f);
    ll mv = ll(t[i] - t[i - 1]) * d;
    deque<int> L, R;
    FOR(j, 1, min(ll(n), 1 + mv)) {
      while (!R.empty() && f[pre][R.back()] >= f[pre][j]) R.pop_back();
      R.eb(j);
    }
    int nxt = min(ll(n), 1 + mv) + 1;
    FOR(j, 1, n) {
      while (!L.empty() && L.front() < j - mv) L.pop_front();
      if (!L.empty()) chkmin(f[now][j], f[pre][L.front()] + abs(j - a[i]));
      if (!R.empty()) chkmin(f[now][j], f[pre][R.front()] + abs(j - a[i]));
      while (!R.empty() && R.front() < j + 1) {
        while (!L.empty() && f[pre][L.back()] >= f[pre][R.front()]) L.pop_back();
        L.eb(R.front()); R.pop_front();
      }
      while (nxt <= n && nxt <= j + mv + 1) {
        while (!R.empty() && f[pre][R.back()] >= f[pre][nxt]) R.pop_back();
        R.eb(nxt++);
      }
    }
  }
  ll ans = 1e18;
  FOR(i, 1, n) chkmin(ans, f[m & 1][i]);
  ans = -ans;
  FOR(i, 1, m) ans += b[i];
  printf("%lld", ans);
}