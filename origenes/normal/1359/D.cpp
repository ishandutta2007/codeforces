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

int a[maxn], n, f[35];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int ans = 0;
  reset(f, 0xc0);
  FOR(i, 1, n) {
    if (a[i] <= 0) FOR(j, 1, 30) f[j] += a[i];
    else {
      ROF(j, 30, a[i]) f[j] += a[i];
      chkmax(f[a[i]], a[i]);
      FOR(j, 1, a[i] - 1) {
        chkmax(f[a[i]], f[j] + a[i]);
        f[j] = -1e9;
      }
      FOR(j, 1, 30) chkmax(ans, f[j] - j);
    }
  }
  printf("%d", ans);
}