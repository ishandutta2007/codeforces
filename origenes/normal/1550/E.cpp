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

int n, k;
int en[maxn][17], best[maxn][17];
char s[maxn];

bool check(int need) {
  REP(j, k) best[n + 1][j] = n + 1;
  ROF(i, n, 1) {
    int good = i + need - 1;
    REP(j, k) {
      best[i][j] = best[i + 1][j];
      if (en[i][j] >= good) best[i][j] = i + need - 1;
    }
  }
  vector<int> f(1 << k, n + 1);
  f[0] = 0;
  REP(mask, 1 << k) if (f[mask] != n + 1) REP(i, k) if ((mask & (1 << i)) == 0) chkmin(f[mask ^ (1 << i)], best[f[mask] + 1][i]);
  return f[(1 << k) - 1] <= n;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  string tmp; cin >> tmp;
  FOR(i, 1, n) s[i] = tmp[i - 1];
  ROF(i, n, 1) {
    if (s[i] == '?') REP(j, k) en[i][j] = max(i, en[i + 1][j]);
    else en[i][s[i] - 'a'] = max(i, en[i + 1][s[i] - 'a']);
  }
  int lo = 0, hi = n / k;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  cout << lo;
}