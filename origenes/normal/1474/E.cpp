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

const int maxn = 112345;

int n;
int p[maxn];

void solve() {
  cin >> n;
  iota(p + 1, p + n + 1, 1);
  ll ans = 0;
  ll l = 1, r = n - 1;
  stack<pii> s;
  REP(i, n - 1) {
    if (i & 1) {
      ans += sqr(r - 1);
      s.emplace(r, 1);
      swap(p[1], p[r]);
      r--;
    } else {
      ans += sqr(l - n);
      s.emplace(l, n);
      swap(p[l], p[n]);
      l++;
    }
  }
  cout << ans << '\n';
  FOR(i, 1, n) cout << p[i] << ' ';
  cout << '\n';
  cout << n - 1 << '\n';
  while (!s.empty()) {
    auto [i, j] = s.top(); s.pop();
    cout << i << ' ' << j << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}