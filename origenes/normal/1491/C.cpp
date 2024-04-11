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

const int maxn = 5123;

int n;
int par[maxn], s[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> s[i];
  iota(par + 1, par + n + 2, 1);
  ll ans = 0;
  FOR(i, 1, n - 1) if (s[i] != 1) {
    int j = i + s[i];
    if (j > n) {
      ans += s[i] - (n - i);
      s[i] = n - i;
    }
    while (s[i] > 1) {
      j = s[i] + i;
      ans++;
      for (int k = Find(j); k <= n; ) {
        int nex = k + s[k] <= n ? Find(k + s[k]) : k + s[k];
        s[k] = max(s[k] - 1, 1);
        if (s[k] == 1) par[k] = Find(k + 1);
        k = nex;
      }
      s[i]--;
    }
  }
  cout << ans + s[n] - 1 << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}