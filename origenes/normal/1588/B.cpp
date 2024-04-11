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

ll ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  ll ret;
  cin >> ret;
  return ret;
}

void solve() {
  int n; cin >> n;
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (ask(1, mi)) hi = mi - 1;
    else lo = mi;
  }
  int i = lo, j = ask(i, n) - ask(i + 1, n) + i + 1;
  int k = ask(j, n) - ask(j + 1, n) + j;
  cout << "! " << i << ' ' << j << ' ' << k << endl;
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}