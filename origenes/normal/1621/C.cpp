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

int query(int i) {
  cout << "? " << i << endl;
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  vector<int> p(n + 1);
  int shift = 0;
  FOR(i, 1, n) if (!p[i]) {
    int q = query(i), qq;
    vector<int> cyc(1, q);
    while (true) {
      qq = query(i);
      if (qq == q) break;
      cyc.eb(qq);
    }
    int m = cyc.size(), j = i, nj = (m - shift % m + 1) % m;
    while (!p[j]) {
      p[j] = cyc[nj];
      j = cyc[nj];
      nj = (nj + 1) % m;
    }
    shift += m + 1;
  }
  cout << '!';
  FOR(i, 1, n) cout << ' ' << p[i];
  cout << '\n';
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}