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

const int maxn = 5123;

int n;
ll t[maxn], x[maxn], need[maxn];
bool f[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> t[i] >> x[i];
  FOR(i, 1, n) need[i] = 1e18;
  REP(i, n) {
    if (need[i] <= t[i]) {
      chkmin(need[i + 1], max(need[i] + abs(x[i + 1] - x[i]), t[i]));
      FOR(j, i + 2, n) {
        if (max(t[i], need[i] + abs(x[i] - x[j])) + abs(x[j] - x[i + 1]) <= t[i + 1]) f[i + 1][j] = true;
        if (need[i] + 2 * abs(x[i] - x[j]) <= t[i] && abs(x[i] - x[i + 1]) + t[i] <= t[i + 1]) f[i + 1][j] = true;
      }
    }
    if (t[i] + abs(x[i] - x[i + 1]) <= t[i + 1]) FOR(j, i + 2, n) f[i + 1][j] |= f[i][j];
    if (i + 1 < n && f[i][i + 1]) {
      chkmin(need[i + 2], max(t[i] + abs(x[i] - x[i + 2]), t[i + 1]));
      FOR(j, i + 3, n) if (max(t[i] + abs(x[i] - x[j]), t[i + 1]) + abs(x[j] - x[i + 2]) <= t[i + 2]) f[i + 2][j] = true;
    }
  }
  if (need[n] <= t[n] || f[n - 1][n]) cout << "YES";
  else cout << "NO";
}