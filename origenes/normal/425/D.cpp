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

const int maxn = 112345;

int n;
vector<int> X[maxn], Y[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    int x, y; cin >> x >> y;
    X[x].eb(y);
    Y[y].eb(x);
  }
  REP(x, 1e5 + 1) sort(all(X[x]));
  REP(y, 1e5 + 1) sort(all(Y[y]));
  int ans = 0;
  REP(x1, 1e5 + 1) {
    REP(i, int(X[x1].size())) {
      int y1 = X[x1][i];
      int cx = int(X[x1].size()) - i - 1, cy = int(Y[y1].end() - lower_bound(all(Y[y1]), x1)) - 1;
      if (cx <= cy) {
        FOR(j, i + 1, X[x1].size() - 1) {
          int y2 = X[x1][j], x2 = x1 + y2 - y1;
          if (x2 <= 1e5 && !X[x2].empty()) {
            auto it = lower_bound(all(X[x2]), y1);
            if (it == X[x2].end() || *it != y1) continue;
            it = lower_bound(all(X[x2]), y2);
            if (it == X[x2].end() || *it != y2) continue;
            ans++;
          }
        }
      } else {
        FOR(j, Y[y1].size() - cy, Y[y1].size() - 1) {
          int x2 = Y[y1][j], y2 = y1 + x2 - x1;
          if (y2 <= 1e5 && !Y[y2].empty()) {
            auto it = lower_bound(all(Y[y2]), x1);
            if (it == Y[y2].end() || *it != x1) continue;
            it = lower_bound(all(Y[y2]), x2);
            if (it == Y[y2].end() || *it != x2) continue;
            ans++;
          }
        }
      }
    }
  }
  cout << ans;
}