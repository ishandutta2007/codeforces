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

const int maxn = 412345;

int a[maxn];
int n, I;

int main() {
  scanf("%d%d", &n, &I);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  int bit = 8 * I / n;
  bit = bit < 25 ? 1 << bit : n;
  int j = 1, d = 0, ans = 0;
  FOR(i, 1, n) {
    while (j <= n) {
      if (j > i && a[j] == a[j - 1]) j++;
      else {
        if (d == bit) break;
        d++, j++;
      }
    }
    chkmax(ans, j - i);
    if (i < n && (i + 1 == j || a[i] != a[i + 1])) d--;
  }
  printf("%d", n - ans);
}