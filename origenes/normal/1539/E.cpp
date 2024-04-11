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

int n, m;
pii f[maxn][2];
int k[maxn], L[maxn][2], R[maxn][2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) {
    cin >> k[i];
    cin >> L[i][0] >> R[i][0] >> L[i][1] >> R[i][1];
  }
  f[n + 1][0] = f[n + 1][1] = {0, m};
  ROF(i, n, 1) REP(j, 2) {
    if (L[i][j] <= k[i] && k[i] <= R[i][j]) {
      f[i][j] = {L[i][1 - j], R[i][1 - j]};
      if (k[i] < f[i + 1][1 - j]._1 || k[i] > f[i + 1][1 - j]._2) {
        int x = max(f[i][j]._1, f[i + 1][j]._1), y = min(f[i][j]._2, f[i + 1][j]._2);
        f[i][j] = x > y ? mp(1, -1) : mp(x, y);
      }
    } else f[i][j] = {1, -1};
  }
  REP(j, 2) if (f[1][j]._1 <= 0 && 0 <= f[1][j]._2) {
    cout << "Yes\n";
    int now = j;
    FOR(i, 1, n) {
      cout << now << ' ';
      if (f[i + 1][1 - now]._1 <= k[i] && k[i] <= f[i + 1][1 - now]._2) now = 1 - now;
    }
    return 0;
  }
  cout << "No";
}