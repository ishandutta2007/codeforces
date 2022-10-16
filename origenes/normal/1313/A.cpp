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

void solve() {
  int a[3];
  REP(i, 3) scanf("%d", a + i);
  sort(a, a + 3);
  if (a[2] == 0) {
    puts("0");
    return;
  }
  if (a[1] == 0) {
    puts("1");
    return;
  }
  if (a[0] == 0) {
    if (a[1] > 1) puts("3");
    else puts("2");
    return;
  }
  int ans = 3;
  a[0]--, a[1]--, a[2]--;
  if (a[0] == 0) {
    if (a[1]) ans++;
    printf("%d\n", ans);
    return;
  }
  if (a[2] == 1) {
    puts("4");
    return;
  }
  a[0]--, a[1]--, a[2] -= 2;
  ans += 2;
  if (a[0]) ans++, a[0]--, a[1]--;
  if (a[0]) ans++;
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}