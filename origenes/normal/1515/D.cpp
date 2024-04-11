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
  int n, lc, rc;
  cin >> n >> lc >> rc;
  vector<int> l(n), r(n);
  REP(i, n) {
    int c; cin >> c;
    c--;
    if (i < lc) l[c]++;
    else r[c]++;
  }
  REP(i, n) {
    int mn = min(l[i], r[i]);
    l[i] -= mn, r[i] -= mn;
  }
  int sl = 0, sr = 0;
  lc = 0, rc = 0;
  REP(i, n) {
    if (l[i] % 2 == 1) {
      l[i]--;
      sl++;
    }
    if (r[i] % 2 == 1) {
      r[i]--;
      sr++;
    }
    lc += l[i];
    rc += r[i];
  }
  int cost = min(sl, sr);
  sl -= cost, sr -= cost;
  if (sl > 0) {
    if (sl > rc) {
      cost += rc;
      sl -= rc;
      rc = 0;
      cost += sl;
    } else {
      cost += sl;
      rc -= sl;
    }
  } else {
    if (sr > lc) {
      cost += lc;
      sr -= lc;
      lc = 0;
      cost += sr;
    } else {
      cost += sr;
      lc -= sr;
    }
  }
  cost += lc / 2 + rc / 2;
  cout << cost << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}