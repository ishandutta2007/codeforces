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

const int maxn = 1123;

int a[maxn], n, c[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  map<int, int> tab;
  FOR(i, 1, n) FOR(j, 2, 31) if (a[i] % j == 0) {
    if (!tab.count(j)) {
      int now = tab.size();
      tab[j] = now + 1;
    }
    c[i] = tab[j];
    break;
  }
  printf("%d\n", int(tab.size()));
  FOR(i, 1, n) printf("%d ", c[i]);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}