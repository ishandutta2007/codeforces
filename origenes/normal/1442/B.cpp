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
const int MOD = 998244353;

int a[maxn], b[maxn], pos[maxn];
bool vis[maxn];

void solve() {
  int n, k;
  cin >> n >> k;
  FOR(i, 1, n) {
    cin >> a[i];
    pos[a[i]] = i;
    vis[i] = false;
  }
  FOR(i, 1, k) {
    cin >> b[i];
    b[i] = pos[b[i]];
    vis[b[i]] = true;
  }
  int ans = 1;
  FOR(i, 1, k) {
    int way = 0;
    if (b[i] > 1 && !vis[b[i] - 1]) way++;
    if (b[i] < n && !vis[b[i] + 1]) way++;
    ans = ans * way % MOD;
    vis[b[i]] = false;
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}