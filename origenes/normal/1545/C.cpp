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

const int maxn = 512;
const int MOD = 998244353;

int n, m;
int cnt[maxn][maxn], a[maxn * 2][maxn], sel[maxn * 2];

void del(int x) {
  sel[x] = 1;
  FOR(i, 1, m) if (!sel[i]) FOR(j, 1, n) if (a[i][j] == a[x][j]) {
    sel[i] = -1;
    FOR(k, 1, n) cnt[k][a[i][k]]--;
    break;
  }
}

void solve() {
  cin >> n;
  m = n * 2;
  int ans = 1;
  FOR(i, 1, n) FOR(j, 1, n) cnt[i][j] = 0;
  FOR(i, 1, m) sel[i] = 0;
  FOR(i, 1, m) FOR(j, 1, n) {
    cin >> a[i][j];
    cnt[j][a[i][j]]++;
  }
  REP(_, n) {
    int x = 0;
    FOR(i, 1, m) if (!sel[i]) FOR(j, 1, n) if (cnt[j][a[i][j]] == 1) {
      x = i;
      break;
    }
    if (x) del(x);
    else {
      ans = (ans + ans) % MOD;
      FOR(i, 1, m) if (!sel[i]) {
        x = i;
        break;
      }
      del(x);
    }
  }
  cout << ans << '\n';
  FOR(i, 1, m) if (sel[i] == 1) cout << i << ' ';
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