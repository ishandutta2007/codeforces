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

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int p; cin >> p;
  return p;
}

void answer(int x) {
  cout << "! " << x << endl;
}

int main() {
  int n; cin >> n;
  int p = ask(1, n), q = 1;
  if (p != n) q = ask(p, n);
  if (p != q) {
    int lo = 1, hi = p - 1;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      int x = ask(mi, p);
      if (x == p) lo = mi;
      else hi = mi - 1;
    }
    answer(lo);
  } else {
    int lo = p + 1, hi = n;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      int x = ask(p, mi);
      if (x == p) hi = mi;
      else lo = mi + 1;
    }
    answer(lo);
  }
}