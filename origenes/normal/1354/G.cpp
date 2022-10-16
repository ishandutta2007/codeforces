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

const int MAX_ITER = 25;

int ask(int l1, int l2, int len) {
  cout << "? " << len << ' ' << len << endl;
  FOR(i, l1, l1 + len - 1) cout << i << ' ';
  cout << endl;
  FOR(i, l2, l2 + len - 1) cout << i << ' ';
  cout << endl;
  string ret;
  cin >> ret;
  if (ret[0] == 'F') return 1;
  if (ret[0] == 'E') return 0;
  if (ret[0] == 'S') return -1;
  assert(0);
}

void solve() {
  int n, k;
  cin >> n >> k;
  REP(_, MAX_ITER) {
    int i = rand() % (n - 1) + 2;
    if (ask(1, i, 1) < 0) {
      cout << "! 1" << endl;
      return;
    }
  }
  for (int l = 1; l <= n; l <<= 1) {
    int len = min(n - l, l);
    if (ask(1, l + 1, len)) {
      int lo = 1, hi = len;
      while (lo < hi) {
        int mi = lo + hi >> 1;
        if (ask(1, l + 1, mi)) hi = mi;
        else lo = mi + 1;
      }
      cout << "! " << lo + l << endl;
      return;
    }
  }
}

int main() {
  srand(time(NULL));
  int T; cin >> T;
  while (T--) solve();
}