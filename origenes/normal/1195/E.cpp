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

const int maxn = 3123;

int n, m, a, b;
int g[maxn * maxn], h[maxn][maxn], f[maxn][maxn];

int main() {
  int y, z;
  ll x;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  scanf("%d%lld%d%d", &g[0], &x, &y, &z);
  FOR(i, 1, n * m) g[i] = (g[i - 1] * x + y) % z;
  FOR(i, 1, n) FOR(j, 1, m) h[i][j] = g[(i - 1) * m + j - 1];
  FOR(i, 1, n) {
    deque<pii> q;
    FOR(j, 1, b) {
      while (!q.empty() && q.back()._2 >= h[i][j]) q.pop_back();
      q.emplace_back(j, h[i][j]);
    }
    f[i][1] = q.front()._2;
    FOR(j, 2, m - b + 1) {
      if (q.front()._1 == j - 1) q.pop_front();
      while (!q.empty() && q.back()._2 >= h[i][j + b - 1]) q.pop_back();
      q.eb(j + b - 1, h[i][j + b - 1]);
      f[i][j] = q.front()._2;
    }
  }
  ll ans = 0;
  FOR(j, 1, m - b + 1) {
    deque<pii> q;
    FOR(i, 1, a) {
      while (!q.empty() && q.back()._2 >= f[i][j]) q.pop_back();
      q.emplace_back(i, f[i][j]);
    }
    ans += q.front()._2;
    FOR(i, 2, n - a + 1) {
      if (q.front()._1 == i - 1) q.pop_front();
      while (!q.empty() && q.back()._2 >= f[i + a - 1][j]) q.pop_back();
      q.eb(i + a - 1, f[i + a - 1][j]);
      ans += q.front()._2;
    }
  }
  printf("%lld", ans);
}