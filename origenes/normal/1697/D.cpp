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

char ask(int t, int p) {
  cout << "? " << t << ' ' << p << endl;
  char x; cin >> x;
  return x;
}

int ask(int t, int l, int r) {
  cout << "? " << t << ' ' << l << ' ' << r << endl;
  int ret; cin >> ret;
  return ret;
}

int main() {
  int n; cin >> n;
  vector<pii> v;
  string s;
  char x = ask(1, 1);
  v.eb(1, x);
  s += x;
  FOR(i, 2, n) {
    int sz = ask(2, 1, i);
    if (sz > size(v)) {
      x = ask(1, i);
      v.eb(i, x);
      s += x;
    } else {
      sort(all(v));
      int lo = 0, hi = size(v) - 1;
      while (lo < hi) {
        int mi = lo + hi + 1 >> 1;
        sz = ask(2, v[mi]._1, i);
        if (sz == int(size(v)) - mi) lo = mi;
        else hi = mi - 1;
      }
      v[lo]._1 = i;
      s += v[lo]._2;
    }
  }
  cout << "! " << s << endl;
}