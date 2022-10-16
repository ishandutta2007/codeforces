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

int n, m, k;
int suf[maxn];
pii segs[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> k;
  FOR(i, 1, m) cin >> segs[i]._1 >> segs[i]._2;
  sort(segs + 1, segs + m + 1, [](pii x, pii y) { return x._1 + x._2 < y._1 + y._2; });
  FOR(i, 1, n - k + 1) {
    int now = 0;
    ROF(j, m, 1) {
      now += max(0, min(i + k - 1, segs[j]._2) - max(i, segs[j]._1) + 1);
      chkmax(suf[j], now);
    }
  }
  int ans = 0;
  FOR(i, 1, n - k + 1) {
    int pre = 0;
    FOR(j, 1, m) {
      pre += max(0, min(i + k - 1, segs[j]._2) - max(i, segs[j]._1) + 1);
      chkmax(ans, pre + suf[j + 1]);
    }
  }
  cout << ans;
}