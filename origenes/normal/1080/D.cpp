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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

int n, t;
ll k, lo[35], hi[35];

int main() {
  lo[1] = hi[1] = 1;
  FOR(i, 2, 31) {
    lo[i] = lo[i - 1] + (1LL << i) - 1;
    hi[i] = hi[i - 1] + (1LL << i * 2 - 2);
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d%lld", &n, &k);
    if (n > 31) {
      printf("YES %d\n", n - 1);
      continue;
    }
    REP(i, n + 1) if (lo[i] <= k && k <= hi[i] + hi[n - i] * sqr((1LL << i) - 1)) {
      printf("YES %d\n", n - i);
      goto label;
    }
    puts("NO");
    label:;
  }
}