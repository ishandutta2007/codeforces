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

int n, m, a[maxn];
bool marked[maxn * maxn];

int main() {
  scanf("%d%d", &n, &m);
  int mx = 0;
  FOR(i, 1, n) mx += (i - 1) / 2;
  if (m > mx) {
    puts("-1");
    return 0;
  }
  FOR(i, 1, n) {
    if (m) {
      int now = (i - 1) / 2;
      if (m >= now) {
        a[i] = i;
        m -= now;
      } else {
        for (int inc = 1; ; inc++) {
          now = (i - 1 - inc) / 2;
          if (m == now) {
            a[i] = i + inc;
            break;
          }
        }
        m = 0;
      }
      if (m == 0) FOR(j, 1, i) FOR(k, j + 1, i) marked[a[i] + a[j]] = true;
    } else {
      for (int j = a[i - 1] + 1; ; j++) if (!marked[j]) {
        a[i] = j;
        break;
      }
      FOR(j, 1, i - 1) marked[a[j] + a[i]] = true;
    }
  }
  FOR(i, 1, n) printf("%d ", a[i]);
}