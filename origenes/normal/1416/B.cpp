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

typedef tuple<int, int, int> tiii;

const int maxn = 11234;

int n;
int a[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int s = accumulate(a + 1, a + n + 1, 0);
  if (s % n != 0) {
    puts("-1");
    return;
  }
  int tar = s / n;
  vector<tiii> ans;
  FOR(i, 2, n) {
    if (a[i] % i != 0) {
      ans.eb(1, i, i - a[i] % i);
      a[i] += i - a[i] % i;
    }
    ans.eb(i, 1, a[i] / i);
  }
  FOR(i, 2, n) ans.eb(1, i, tar);
  printf("%d\n", int(ans.size()));
  for (auto [i, j, x] : ans) printf("%d %d %d\n", i, j, x);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}