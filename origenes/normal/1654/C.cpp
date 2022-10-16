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
  int n; cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  sort(all(a));
  ll s = accumulate(all(a), 0LL);
  priority_queue<ll> q; q.emplace(s);
  vector<ll> b;
  REP(i, n - 1) {
    while (true) {
      ll w = q.top(); q.pop();
      if (a.back() == w) {
        a.pop_back();
        continue;
      }
      q.emplace(w / 2);
      q.emplace((w + 1) / 2);
      break;
    }
  }
  while (!q.empty()) {
    b.eb(q.top());
    q.pop();
  }
  sort(all(b));
  if (a == b) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}