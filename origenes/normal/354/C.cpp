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

const int maxn = 312345;

int n, k;
int a[maxn];

bool check(int x) {
  int i = 1;
  while (i <= n) {
    if (a[i] % x > k) return false;
    i = lower_bound(a + i, a + n + 1, a[i] / x * x + k + 1) - a;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  if (a[1] <= k + 1) {
    printf("%d", a[1]);
    return 0;
  }
  ROF(i, a[1], k + 1) if (check(i)) {
    printf("%d", i);
    return 0;
  }
  assert(0);
}