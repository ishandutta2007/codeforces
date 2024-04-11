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

int n, m;
ll b;
int prob[maxn], id[maxn], x[maxn], k[maxn];
ll f[1 << 20];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> b;
  FOR(i, 1, n) {
    id[i] = i;
    int tot;
    cin >> x[i] >> k[i] >> tot;
    REP(j, tot) {
      int now;
      cin >> now; now--;
      prob[i] |= 1 << now;
    }
  }
  sort(id + 1, id + n + 1, [](int i, int j){ return k[i] < k[j]; });
  reset(f, 0x3f);
  f[0] = 0;
  ll ans = 5e18;
  FOR(_i, 1, n) {
    int i = id[_i];
    ROF(mask, (1 << m) - 1, 0) chkmin(f[mask | prob[i]], f[mask] + x[i]);
    chkmin(ans, f[(1 << m) - 1] + b * k[i]);
  }
  if (ans > 2e18) ans = -1;
  cout << ans;
}