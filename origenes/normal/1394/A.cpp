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

int a[maxn];
int n, d, m;

int main() {
  scanf("%d%d%d", &n, &d, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  vector<int> large, small;
  FOR(i, 1, n) {
    if (a[i] > m) large.eb(a[i]);
    else small.eb(a[i]);
  }
  sort(all(large), greater<>());
  sort(all(small));
  if (large.empty() || large.size() == 1) {
    printf("%lld", accumulate(a + 1, a + n + 1, 0LL));
    return 0;
  }
  n--;
  stack<int> s;
  ll ans = large[0];
  FOR(i, 1, int(large.size()) - 1) {
    if (n < d + 1) break;
    n -= d + 1;
    s.emplace(large[i]);
    ans += large[i];
  }
  while (!small.empty() && n--) {
    ans += small.back();
    small.pop_back();
  }
  while (!s.empty() && !small.empty()) {
    ll gain = -s.top(); s.pop();
    int cnt = d + 1;
    while (!small.empty() && cnt--) {
      gain += small.back();
      small.pop_back();
    }
    if (gain > 0) ans += gain;
    else break;
  }
  printf("%lld", ans);
}