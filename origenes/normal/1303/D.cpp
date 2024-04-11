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

ll n;
int m, cnt[65];

void solve() {
  scanf("%lld%d", &n, &m);
  reset(cnt, 0);
  ll s = 0;
  while (m--) {
    int x; scanf("%d", &x);
    REP(i, 31) if (x == 1 << i) cnt[i]++;
    s += x;
  }
  if (s < n) {
    puts("-1");
    return;
  }
  int ans = 0;
  REP(i, 60) {
    int need = (n >> i) & 1;
    if (cnt[i] < need) {
      FOR(j, i + 1, 60) if (cnt[j]) {
        cnt[j]--;
        FOR(k, i, j - 1) cnt[k]++;
        cnt[i]++;
        ans += j - i;
        break;
      }
    }
    cnt[i] -= need;
    cnt[i + 1] += cnt[i] / 2;
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}