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

bool ask(int x, int y) {
  cout << 1 << ' ' << x << ' ' << y << endl;
  string ret;
  cin >> ret;
  return ret == "TAK";
}

int go(int lo, int hi) {
  if (lo > hi) return -1;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (ask(mi, mi + 1)) hi = mi;
    else lo = mi + 1;
  }
  return lo;
}

int main() {
  int n, k, x, y;
  cin >> n >> k;
  x = go(1, n), y = go(1, x - 1);
  if (y == -1 || !ask(y, x)) y = go(x + 1, n);
  cout << 2 << ' ' << x << ' ' << y << endl;
}