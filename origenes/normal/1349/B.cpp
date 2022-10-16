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

int n, k;
int a[maxn];

void solve() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  vector<int> ks;
  FOR(i, 1, n) if (a[i] == k) ks.eb(i);
  if (ks.empty()) {
    puts("no");
    return;
  }
  if (n == 1) {
    puts("yes");
    return;
  }
  FOR(i, 2, n) if (a[i] >= k && a[i - 1] >= k) {
    puts("yes");
    return;
  }
  FOR(i, 3, n) if (a[i] >= k && a[i - 2] >= k) {
    puts("yes");
    return;
  }
  puts("no");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}