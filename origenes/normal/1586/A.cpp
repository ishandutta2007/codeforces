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

const int maxn = 21234;

bool vis[maxn];

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  int s = accumulate(a.begin() + 1, a.end(), 0);
  if (vis[s]) {
    cout << n << '\n';
    FOR(i, 1, n) cout << i << ' ';
    cout << '\n';
    return;
  }
  FOR(i, 1, n) if (vis[s - a[i]]) {
    cout << n - 1 << '\n';
    FOR(j, 1, n) if (j != i) cout << j << ' ';
    cout << '\n';
    return;
  }
  FOR(i, 1, n) FOR(j, i + 1, n) if (vis[s - a[i] - a[j]]) {
    cout << n - 2 << '\n';
    FOR(k, 1, n) if (k != i && k != j) cout << k << ' ';
    cout << '\n';
    return;
  }
  assert(0);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  FOR(i, 2, 20000) if (!vis[i]) for (int j = i + i; j <= 20000; j += i) vis[j] = true;
  int T; cin >> T;
  while (T--) solve();
}