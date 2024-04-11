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

int n, s;
int a[maxn];

void solve() {
  scanf("%d%d", &n, &s);
  FOR(i, 1, n) scanf("%d", a + i);
  int mx = 0, sum = 0, skip = 0;
  FOR(i, 1, n) {
    sum += a[i];
    if (a[i] > a[mx]) mx = i;
    if (sum > s) {
      if (skip) break;
      skip = mx;
      sum -= a[mx];
    }
  }
  printf("%d\n", skip);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}