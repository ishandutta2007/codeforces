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
  int n; scanf("%d", &n);
  if (n == 1) {
    puts("FastestFinger");
    return;
  }
  if (n == 2) {
    puts("Ashishgup");
    return;
  }
  if (n % 2 == 0 && n % 4 != 0) {
    n /= 2;
    for (int i = 3; sqr(i) <= n; i += 2) if (n % i == 0) {
      puts("Ashishgup");
      return;
    }
    puts("FastestFinger");
    return;
  }
  while (n % 2 == 0) n /= 2;
  puts(n > 1 ? "Ashishgup" : "FastestFinger");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}