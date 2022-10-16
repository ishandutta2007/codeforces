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

const int maxn = 112345;

int n, m;
ll h[maxn], p[maxn];

bool check(ll t) {
  int j = 1;
  FOR(i, 1, n) {
    ll en;
    if (j == m + 1) return true;
    if (h[i] < p[j]) en = h[i] + t;
    else {
      if (p[j] < h[i] - t) return false;
      ll x = h[i] - p[j];
      en = max((t - x) / 2, t - 2 * x) + h[i];
    }
    while (j <= m && p[j] <= en) j++;
  }
  return j == m + 1;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%lld", h + i);
  FOR(i, 1, m) scanf("%lld", p + i);
  ll lo = 0, hi = 2e10 + 5;
  while (lo < hi) {
    ll mi = lo + (hi - lo >> 1);
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%lld", lo);
}