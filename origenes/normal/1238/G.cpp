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

pair<int, pii> f[maxn];
int n, m, c0, c;

ll solve() {
  scanf("%d%d%d%d", &n, &m, &c, &c0);
  FOR(i, 1, n) {
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);
    f[i] = {t, mp(a, b)};
  }
  n++;
  f[n] = {m, {0, 0}};
  if (c0 >= m) return 0;
  sort(f + 1, f + n + 1);
  map<int, int> have;
  have[0] = c0;
  int sum = c0, j = 0;
  ll cost = 0;
  FOR(i, 1, n) {
    int t = f[i]._1, a = f[i]._2._1, b = f[i]._2._2;
    if (sum < t - j) return -1;
    while (j < t) {
      if (have.begin()->_2 + j <= t) {
        cost += have.begin()->_1 * ll(have.begin()->_2);
        j += have.begin()->_2;
        sum -= have.begin()->_2;
        have.erase(have.begin());
      } else {
        ll need = t - j;
        have.begin()->_2 -= t - j;
        cost += have.begin()->_1 * need;
        sum -= need;
        j = t;
      }
    }
    sum += a;
    have[b] += a;
    while (sum > c) {
      int diff = sum - c;
      if (have.rbegin()->_2 > diff) {
        have.rbegin()->_2 -= diff;
        sum = c;
      } else {
        sum -= have.rbegin()->_2;
        have.erase(have.rbegin()->_1);
      }
    }
  }
  return cost;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) printf("%lld\n", solve());
}