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

const int maxn = 212345;
const int BLK = 512;

int n, m;
int x[maxn], y[maxn], last[maxn], events[maxn];
int bad[BLK][BLK];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) cin >> x[i] >> y[i];
  int large = 0;
  FOR(clk, 1, m) {
    int op, k; cin >> op >> k;
    if (op == 1) {
      if (x[k] + y[k] >= BLK) {
        for (long long i = clk + x[k]; i <= m; i += x[k] + y[k]) {
          events[i]++;
          if (i + y[k] <= m) events[i + y[k]]--;
        }
      } else {
        FOR(i, x[k], x[k] + y[k] - 1) bad[x[k] + y[k]][(clk + i) % (x[k] + y[k])]++;
      }
      last[k] = clk;
    } else {
      if (x[k] + y[k] < BLK) {
        FOR(i, x[k], x[k] + y[k] - 1) bad[x[k] + y[k]][(last[k] + i) % (x[k] + y[k])]--;
      } else {
        for (long long i = last[k] + x[k]; i <= m; i += x[k] + y[k]) {
          events[i]--;
          if (i < clk) large--;
          if (i + y[k] <= m) events[i + y[k]]++;
          if (i + y[k] < clk) large++;
        }
      }
    }
    large += events[clk];
    int ans = large;
    FOR(i, 1, BLK - 1) ans += bad[i][clk % i];
    cout << ans << '\n';
  }
}