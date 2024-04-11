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

int n;
vector<int> G[maxn];

void solve() {
  cin >> n;
  if (n == 1) {
    cout << "0\n";
    return;
  }
  FOR(i, 1, n) G[i].clear();
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  bool line = true;
  FOR(i, 1, n) if (size(G[i]) > 2) {
    line = false;
    break;
  }
  if (line) {
    cout << "1\n";
    return;
  }
  int ans = 0;
  vector<bool> vis(n + 1);
  FOR(i, 1, n) if (size(G[i]) == 1) {
    ans++;
    int j = G[i][0], k = i;
    while (size(G[j]) <= 2) {
      k ^= G[j][0] ^ G[j][1];
      swap(j, k);
    }
    if (!vis[j]) {
      vis[j] = true;
      ans--;
    }
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