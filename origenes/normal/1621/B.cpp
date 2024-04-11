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
  int n;
  cin >> n;
  int L = 1e9 + 1, R = 0, len = 0, C = 0, cl = 0, cr = 0;
  while (n--) {
    int l, r, c;
    cin >> l >> r >> c;
    if (l < L || (l == L && c < cl)) {
      L = l;
      cl = c;
    }
    if (r > R || (r == R && c < cr)) {
      R = r;
      cr = c;
    }
    if (r - l + 1 > len || (len == r - l + 1 && c < C)) {
      len = r - l + 1;
      C = c;
    }
    if (C < cl + cr && len == R - L + 1) cout << C << '\n';
    else cout << cl + cr << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}