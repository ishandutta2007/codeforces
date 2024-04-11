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

int n, q;
int a[35];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  REP(i, n) cin >> a[i];
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos, val;
      cin >> pos >> val;
      a[pos] = val;
      continue;
    }
    vector<ll> now(a, a + n);
    int x;
    ll k;
    cin >> x >> k;
    ll ans = 0, have = accumulate(a, a + x + 1, 0LL);
    while (have < k) {
      FOR(i, x + 1, n - 1) {
        ll inc = min(now[i], (k - have) / (1LL << i - x));
        ans += inc * ((1 << i - x) - 1);
        have += inc * (1 << i - x);
        now[i] -= inc;
        now[x] += inc * (1 << i - x);
      }
      ll mx = 0;
      REP(i, x + 1) mx += (1 << i) * now[i];
      if (mx >= k) {
        ans += k - have;
        break;
      }
      int j = x + 1;
      while (j < n && !now[j]) j++;
      if (j == n) {
        ans = -1;
        break;
      }
      ans += j - x;
      have += 2;
      now[x] += 2;
      FOR(i, x + 1, j - 1) now[i]++;
      now[j]--;
    }
    cout << ans << '\n';
  }
}