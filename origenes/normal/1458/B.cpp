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

const int maxn = 112;

int n;
int a[maxn], b[maxn];
int f[2][maxn][maxn * maxn * 4];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i] >> b[i];
    a[i] *= 2, b[i] *= 2;
  }
  reset(f[0], -1);
  auto c = [](int x) {
    return x + maxn * maxn * 2;
  };
  f[0][0][c(0)] = 0;
  FOR(i, 1, n) {
    int now = i & 1, pre = 1 - now;
    reset(f[now], -1);
    REP(j, i) FOR(k, -20000, 20000) if (f[pre][j][c(k)] != -1) {
      int nk = k - b[i] / 2;
      int gain = k > 0 ? k - max(nk, 0) : 0;
      chkmax(f[now][j][c(nk)], f[pre][j][c(k)] + gain);
      nk = k + a[i] - b[i];
      gain = k < 0 ? b[i] + min(-k, a[i] - b[i]) : b[i];
      chkmax(f[now][j + 1][c(nk)], f[pre][j][c(k)] + gain);
    }
  }
  cout << fixed << setprecision(10);
  FOR(j, 1, n) {
    int mx = 0;
    FOR(k, -20000, 20000) chkmax(mx, f[n & 1][j][c(k)]);
    cout << (double) mx / 2 << ' ';
  }
}