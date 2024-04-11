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

int n, x;
int a[maxn];

void solve() {
  scanf("%d%d", &n, &x);
  bool f = false;
  FOR(i, 1, n) {
    scanf("%d", a + i);
    if (a[i] == x) f = true;
  }
  if (f) {
    puts("1");
    return;
  }
  int mx = a[1];
  FOR(i, 2, n) chkmax(mx, a[i]);
  printf("%d\n", max(2, (x + mx - 1) / mx));
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}