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
  int L, R;
  cin >> L >> R;
  R -= L;
  vector<tuple<int, int, int>> edges;
  int s = 1;
  ROF(i, 19, 0) if (R & (1 << i)) {
    edges.eb(1, 21 - i, s);
    s += 1 << i;
  }
  int t = 22;
  edges.eb(1, t, L);
  ROF(i, 19, 0) {
    ROF(j, i - 1, 0) edges.eb(21 - i, 21 - j, 1 << j);
    edges.eb(21 - i, t, L);
  }
  cout << "YES\n";
  cout << "22 " << edges.size() << '\n';
  for (auto [u, v, w] : edges) cout << u << ' ' << v << ' ' << w << '\n';
}