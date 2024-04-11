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

const int maxn = 1123456;

vector<int> G[maxn], query;
int s[maxn], n;

int main() {
  scanf("%d", &n);
  int no = 0;
  FOR(i, 1, n) {
    int l; scanf("%d", &l);
    G[i].resize(l);
    for (auto &x : G[i]) scanf("%d", &x);
    int mx = -1, mn = 1e6 + 5;
    bool good = false;
    ROF(j, l - 1, 0) {
      if (G[i][j] < mx) {
        good = true;
        break;
      }
      chkmax(mx, G[i][j]);
      chkmin(mn, G[i][j]);
    }
    if (!good) {
      no++;
      s[mn]++;
      query.eb(mx);
    }
  }
  ll ans = sqr(ll(n)) - sqr(ll(no));
  FOR(i, 1, int(1e6)) s[i] = s[i] + s[i - 1];
  for (auto mx : query) if (mx > 0) ans += s[mx - 1];
  printf("%lld", ans);
}