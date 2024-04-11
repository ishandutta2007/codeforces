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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector<int> segs;
  vector<pii> ans;
  int i = 1, last = 0;
  while (i <= n) {
    int j = i + 1;
    while (j <= n && a[i] != a[j]) j++;
    if (j > n) {
      cout << "-1\n";
      return;
    }
    segs.eb((j - i) * 2);
    FOR(k, i + 1, j - 1) ans.eb(last + j - i + k - i, a[k]);
    vector<int> tmp(n + 1);
    FOR(k, i + 1, j - 1) tmp[k] = a[j - k + i];
    FOR(k, i + 2, j) a[k] = tmp[k - 1];
    last += (j - i) * 2;
    i += 2;
  }
  cout << size(ans) << '\n';
  for (auto [p, c] : ans) cout << p << ' ' << c << '\n';
  cout << size(segs) << '\n';
  for (auto x : segs) cout << x << ' ';
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