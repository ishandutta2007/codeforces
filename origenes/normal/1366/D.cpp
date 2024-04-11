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

const int maxa = 11234567;
const int maxn = 512345;

int n;
int vis[maxa], a[maxn], ans[2][maxn];

int main() {
  vis[1] = 1;
  FOR(i, 2, 1e7) if (!vis[i]) {
    vis[i] = i;
    for (ll j = ll(i) * i; j <= 1e7; j += i) vis[j] = i;
  }
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) {
    map<int, int> cnt;
    while (a[i] != 1) {
      cnt[vis[a[i]]]++;
      a[i] /= vis[a[i]];
    }
    if (cnt.size() >= 2) {
      ans[0][i] = ans[1][i] = 1;
      while (cnt.size() > 1) {
        ans[0][i] *= cnt.begin()->_1;
        if (!--cnt.begin()->_2) cnt.erase(cnt.begin());
      }
      while (cnt.begin()->_2--) ans[1][i] *= cnt.begin()->_1;
    } else ans[0][i] = ans[1][i] = -1;
  }
  REP(j, 2) {
    FOR(i, 1, n) printf("%d ", ans[j][i]);
    putchar('\n');
  }
}