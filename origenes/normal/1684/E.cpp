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
  int n, k;
  cin >> n >> k;
  vector<bool> vis(n);
  vector<int> a(n);
  map<int, int> cnt;
  REP(i, n) {
    cin >> a[i];
    if (a[i] < n) vis[a[i]] = true;
    cnt[a[i]]++;
  }
  sort(all(a), greater<>());
  int mex = 0, need = 0;
  REP(i, k) {
    while (mex < n && vis[mex]) mex++;
    if (mex < n && a[i] > mex) {
      vis[mex] = true;
      need++;
    }
  }
  while (mex < n && vis[mex]) mex++;
  vector<int> seq;
  int ans = 0;
  for (auto [v, c] : cnt) if (v >= mex) {
    seq.eb(c);
    ans++;
  }
  sort(all(seq));
  for (auto x : seq) {
    if (x > need) break;
    ans--;
    need -= x;
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