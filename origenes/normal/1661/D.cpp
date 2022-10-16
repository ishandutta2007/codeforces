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
  int n, k;
  cin >> n >> k;
  vector<ll> b(n + 1);
  FOR(i, 1, n) cin >> b[i];
  ll ans = 0, off = 0, cnt = 0;
  queue<pair<int, ll>> q;
  ROF(i, n, k) {
    off -= cnt;
    while (!q.empty()) {
      auto [p, c] = q.front();
      if (p - i >= k) {
        cnt -= c;
        q.pop();
      } else break;
    }
    if (b[i] - off > 0) {
      ll c = (b[i] - off + k - 1) / k;
      off += k * c;
      ans += c;
      cnt += c;
      q.emplace(i, c);
    }
  }
  ll need = 0;
  ROF(i, k - 1, 1) {
    off -= cnt;
    while (!q.empty()) {
      auto [p, c] = q.front();
      if (p - i >= k) {
        cnt -= c;
        q.pop();
      } else break;
    }
    b[i] -= off;
    if (b[i] > 0) chkmax(need, (b[i] + i - 1) / i);
  }
  cout << ans + need;
}