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

const int maxn = 2123;

int n;
string mat[maxn];
int L[maxn], R[maxn], U[maxn], D[maxn];

void solve() {
  cin >> n;
  REP(i, n) cin >> mat[i];
  vector<vector<pii>> digits;
  digits.resize(10);
  REP(i, n) REP(j, n) digits[mat[i][j] - '0'].eb(i, j);
  FOR(d, '0', '9') {
    REP(i, n) {
      L[i] = n;
      R[i] = -1;
      U[i] = n;
      D[i] = -1;
    }
    for (auto [x, y] : digits[d - '0']) {
      chkmin(L[x], y);
      chkmax(R[x], y);
      chkmin(U[y], x);
      chkmax(D[y], x);
    }
    int ans = 0;
    REP(x1, n) if (L[x1] != n) {
      int y1 = L[x1], Y1 = R[x1];
      int w = max(x1, n - 1 - x1);
      REP(x2, n) if (L[x2] != n) {
        int y2 = L[x2];
        chkmax(ans, abs(w * (y1 - y2)));
        chkmax(ans, abs(w * (Y1 - y2)));
        y2 = R[x2];
        chkmax(ans, abs(w * (y1 - y2)));
        chkmax(ans, abs(w * (Y1 - y2)));
      }
      chkmax(ans, abs(max(x1, n - 1 - x1) * (y1 - Y1)));
    }
    REP(x1, n) if (U[x1] != n) {
      int y1 = U[x1], Y1 = D[x1];
      int w = max(x1, n - 1 - x1);
      REP(x2, n) if (U[x2] != n) {
        int y2 = U[x2];
        chkmax(ans, abs(w * (y1 - y2)));
        chkmax(ans, abs(w * (Y1 - y2)));
        y2 = D[x2];
        chkmax(ans, abs(w * (y1 - y2)));
        chkmax(ans, abs(w * (Y1 - y2)));
      }
      chkmax(ans, abs(max(x1, n - 1 - x1) * (y1 - Y1)));
    }
    cout << ans << ' ';
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}