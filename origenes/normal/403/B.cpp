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

const int maxn = 5123;

int n, m;
int a[maxn], g[maxn];
bool vis[112345];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  set<int> b;
  FOR(i, 1, m) {
    int x; scanf("%d", &x);
    b.emplace(x);
  }
  g[1] = a[1];
  FOR(i, 2, n) g[i] = gcd(g[i - 1], a[i]);
  int d = 1, ans = 0;
  vector<int> primes;
  FOR(i, 2, 4e4) if (!vis[i]) {
    primes.eb(i);
    for (int j = i + i; j <= 4e4; j += i) vis[j] = true;
  }
  ROF(i, n, 1) {
    auto f = [&](int x) -> int {
      if (x == 1) return 0;
      int ret = 0;
      for (auto p : primes) {
        while (x % p == 0) {
          if (b.count(p)) ret--;
          else ret++;
          x /= p;
        }
        if (x == 1) break;
      }
      if (x != 1) {
        if (b.count(x)) ret--;
        else ret++;
      }
      return ret;
    };
    g[i] /= d;
    if (f(g[i]) <= 0) d *= g[i];
    ans += f(a[i] / d);
  }
  printf("%d", ans);
}