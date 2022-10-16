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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k; cin >> n >> k;
  vector<ll> a(n + 1);
  vector<int> cnt(n + 1);
  FOR(i, 1, n) {
    cin >> a[i];
    if (a[i] == 0) {
      a[i] = -k;
      cnt[i] = 1;
    }
    a[i] += a[i - 1];
    cnt[i] += cnt[i - 1];
  }
  if (a[n] > 0 || -a[n] > cnt[n] * 2LL * k) {
    cout << "-1\n";
    return 0;
  }
  ll ans = 0;
  REP(i, n + 1) FOR(j, i, n) {
    ll L = -a[n] - (cnt[n] - (cnt[j] - cnt[i])) * 2LL * k, R = -a[n];
    ll mv = (cnt[j] - cnt[i]) * 2LL * k;
    chkmax(ans, a[j] - a[i] + 1 + min(R, max(L, mv)));
    chkmax(ans, a[i] - a[j] + 1 - max(0LL, L));
  }
  cout << ans;
}