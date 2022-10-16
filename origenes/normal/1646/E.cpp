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

const int maxn = 1123456;

bitset<20 * maxn> vis;
int vis2[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m; cin >> n >> m;
  vector<int> cnt(21);
  FOR(i, 1, 20) {
    FOR(j, 1, m) vis[i * j] = 1;
    cnt[i] = vis.count();
  }
  ll ans = 1;
  FOR(i, 2, n) if (!vis2[i]) {
    int j = 0;
    for (ll k = i; k <= n; k *= i) {
      vis2[k] = 1;
      j++;
    }
    ans += cnt[j];
  }
  cout << ans;
}