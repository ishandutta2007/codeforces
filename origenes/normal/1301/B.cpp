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

int n, a[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int k = 0, m = 0;
  vector<int> pending;
  FOR(i, 2, n) {
    if (a[i] != -1) {
      if (a[i - 1] == -1) pending.eb(a[i]);
      else chkmax(m, abs(a[i] - a[i - 1]));
    } else if (a[i - 1] != -1) pending.eb(a[i - 1]);
  }
  if (pending.size() > 1) {
    sort(all(pending));
    k = (pending.front() + pending.back()) / 2;
    chkmax(m, (pending.back() - pending.front() + 1) / 2);
  } else if (pending.size() == 1) k = pending[0];
  printf("%d %d\n", m, k);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}