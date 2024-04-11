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

int n;
int a[maxn], vis[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) vis[i] = 0;
  vector<int> ans;
  int i;
  for (i = 1; !vis[i]; i = i - a[i]) vis[i] = 1;
  for (; vis[i] != 2; i = i - a[i]) {
    ans.eb(i);
    vis[i]++;
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
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