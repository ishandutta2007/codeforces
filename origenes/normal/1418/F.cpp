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

int n, m;
ll L, R;
vector<int> f[maxn];

int main() {
  scanf("%d%d%lld%lld", &n, &m, &L, &R);
  FOR(i, 1, n) for (int j = i; j <= n; j += i) f[j].eb(i);
  FOR(i, 1, n) {
    ll l = max((L + i - 1) / i, 1LL), r = min(R / i, ll(m));
    if (l > r) {
      puts("-1");
      continue;
    }
    l--;
    bool good = false;
    for (auto j : f[i]) {
      ll p = i / j, up = min(n / p, ll(m));
      for (ll x = j + 1, y; x <= up; x = y + 1) {
        if (l / x == 0 && r / x == 0) break;
        if (l / x + 1 <= r / x) {
          printf("%d %lld %lld %lld\n", i, (l / x + 1) * x, p * x, (l / x + 1) * j);
          good = true;
          break;
        }
        y = min(up, min(l / x ? l / (l / x): up , r / (r / x)));
      }
      if (good) break;
    }
    if (!good) puts("-1");
  }
}