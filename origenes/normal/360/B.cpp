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

const int maxn = 2123;

int f[maxn], a[maxn];
int n, k;

bool check(int x) {
  int best = 1e9;
  FOR(i, 1, n) {
    f[i] = i - 1;
    FOR(j, 1, i - 1) if ((abs(a[i] - a[j]) + i - j - 1) / (i - j) <= x) chkmin(f[i], f[j] + i - j - 1);
    chkmin(best, f[i] + n - i);
  }
  return best <= k;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  int lo = 0, hi = 2e9 + 5;
  while (lo < hi) {
    int mi = (hi - lo >> 1) + lo;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%d", lo);
}