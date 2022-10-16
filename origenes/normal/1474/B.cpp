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

const int maxn = 51234;

bool vis[maxn];

void solve() {
  ll d;
  cin >> d;
  ll x, y;
  for (x = d + 1; ; x++) if (!vis[x]) break;
  for (y = d + x; ; y++) if (!vis[y]) break;
  cout << x * y << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  FOR(i, 2, 50000) if (!vis[i]) for (int j = 2 * i; j <= 50000; j += i) vis[j] = true;
  int T; cin >> T;
  while (T--) solve();
}