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

int ask(int u, int sz, int l, int r) {
  cout << 1 << ' ' << sz << ' ' << u;
  FOR(i, l, r) cout << ' ' << i;
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}

void answer(int u, int sz) {
  cout << 1 << ' ' << sz - 1 << ' ' << u;
  FOR(i, 1, sz) if (i != u) cout << ' ' << i;
  cout << endl;
  int ret;
  cin >> ret;
  cout << -1 << ' ' << ret << endl;
}

int T, n;

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int dis = ask(1, n - 1, 2, n), lo = 2, hi = n;
    while (lo < hi) {
      int mi = lo + hi >> 1, now = ask(1, mi - lo + 1, lo, mi);
      if (now == dis) hi = mi;
      else lo = mi + 1;
    }
    answer(lo, n);
  }
}