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

int n;
int a[maxn], cnt[maxn], f[maxn];
ll r[maxn], h[maxn];

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  scanf("%d", &n);
  REP(i, n) r[i] = (ll(rng()) << 32LL) | rng();
  REP(i, n) {
    scanf("%d", a + i);
    a[i]--;
    int &c = cnt[a[i]], j = a[i];
    h[i + 1] = h[i] - c * r[j] + (c + 1) % 3 * r[j];
    c = (c + 1) % 3;
  }
  int j = 0;
  map<ll, int> occ;
  ll ans = 0;
  REP(i, n) {
    f[a[i]]++;
    if (f[a[i]] > 3) {
      while (a[j] != a[i]) {
        f[a[j]]--;
        occ[h[j]]--;
        j++;
      }
      f[a[j]]--, occ[h[j]]--;
      j++;
    }
    ans += occ[h[i + 1]];
    occ[h[i]]++;
  }
  printf("%lld", ans);
}