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
  int n, W; cin >> n >> W;
  vector<int> w(n);
  REP(i, n) cin >> w[i];
  vector<int> cnt(30);
  REP(i, n) REP(j, 20) if (w[i] == (1 << j)) {
    cnt[j]++;
    break;
  }
  int ans = 0, rem = n;
  while (rem) {
    int now = W;
    ans++;
    ROF(j, 29, 0) while (cnt[j] && now >= (1 << j)) {
      cnt[j]--;
      rem--;
      now -= (1 << j);
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