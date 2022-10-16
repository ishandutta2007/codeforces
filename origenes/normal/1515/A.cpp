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
  int n, x;
  cin >> n >> x;
  vector<int> w(n);
  REP(i, n) cin >> w[i];
  if (accumulate(all(w), 0) == x) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  sort(all(w));
  queue<int> ans;
  int s = 0;
  REP(i, n) {
    s += w[i];
    ans.emplace(w[i]);
    if (s == x) {
      ans.pop();
      s += w[n - 1] - w[0];
      ans.emplace(w[n - 1]);
      swap(w[n - 1], w[0]);
    }
  }
  while (!ans.empty()) {
    cout << ans.front() << ' ';
    ans.pop();
  }
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