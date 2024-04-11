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

int n, k;
int a[maxn], vis[maxn];
vector<int> primes;
vector<pii> fac[maxn];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 2, int(1e5)) if (!vis[i]) {
    primes.eb(i);
    for (int j = i; j <= 1e5; j += i) if (!vis[j]) vis[j] = i;
  }
  FOR(i, 1, n) {
    scanf("%d", a + i);
    if (a[i] == 1) continue;
    int cur = a[i], now = vis[a[i]];
    vector<pii> tmp;
    tmp.eb(now, 1);
    while ((cur /= vis[cur]) && cur != 1) {
      if (now == vis[cur]) tmp.back()._2++;
      else now = vis[cur], tmp.eb(now, 1);
    }
    for (auto &x : tmp) {
      x._2 %= k;
      if (x._2) fac[i].eb(x);
    }
  }
  map<vector<pii>, int> cnt;
  FOR(i, 1, n) cnt[fac[i]]++;
  ll ans = 0;
  FOR(i, 1, n) {
    auto req = fac[i];
    for (auto &x : req) x._2 = k - x._2;
    if (!--cnt[fac[i]]) cnt.erase(fac[i]);
    ans += cnt[req];
  }
  printf("%lld", ans);
}