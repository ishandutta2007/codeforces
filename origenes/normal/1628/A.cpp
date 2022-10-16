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
  vector<queue<int>> q(n + 1);
  FOR(i, 1, n) {
    int a;
    cin >> a;
    q[a].emplace(i);
  }
  vector<int> b;
  int tail = 0;
  while (true) {
    int now = 0, ptail = tail;
    while (!q[0].empty() && q[0].front() <= tail) q[0].pop();
    if (q[0].empty()) {
      FOR(i, tail + 1, n) b.eb(0);
      break;
    }
    while (!q[now].empty()) {
      while (!q[now].empty() && q[now].front() <= ptail) q[now].pop();
      if (q[now].empty()) break;
      chkmax(tail, q[now].front());
      now++;
    }
    b.eb(now);
  }
  cout << size(b) << '\n';
  for (auto x : b) cout << x << ' ';
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