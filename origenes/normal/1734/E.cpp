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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n;
  cin >> n;
  vector<int> b(n);
  REP(i, n) cin >> b[i];
  vector<vector<int>> a(n, vector<int>(n));
  REP(i, n) REP(j, n) a[i][j] = i * j % n;
  REP(i, n) {
    int d = b[i] - a[i][i];
    REP(j, n) a[i][j] = (a[i][j] + d + n) % n;
  }
  REP(i, n) {
    REP(j, n) cout << a[i][j] << ' ';
    cout << '\n';
  }
}