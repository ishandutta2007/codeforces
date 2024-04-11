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

const int maxn = 112;

int a[maxn], ans, n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 2, n) {
    if (a[i] == 3 && a[i - 1] == 2) {
      puts("Infinite");
      return 0;
    }
    if (a[i] == 2 && a[i - 1] == 3) {
      puts("Infinite");
      return 0;
    }
    if (abs(a[i] - a[i - 1]) == 1) ans += 3;
    else ans += 4;
    if (i >= 3 && a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) ans--;
  }
  puts("Finite");
  printf("%d", ans);
}