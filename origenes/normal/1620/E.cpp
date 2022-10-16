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

const int maxn = 512345;

vector<int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int q, n = 0;
  cin >> q;
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int x; cin >> x;
      G[x].eb(n++);
    } else {
      int x, y;
      cin >> x >> y;
      if (x == y) continue;
      if (size(G[x]) > size(G[y])) swap(G[x], G[y]);
      for (auto i : G[x]) G[y].eb(i);
      G[x].clear();
    }
  }
  vector<int> a(n);
  FOR(i, 1, 5e5) for (auto j : G[i]) a[j] = i;
  for (auto x : a) cout << x << ' ';
}