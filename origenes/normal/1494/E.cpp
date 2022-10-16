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
  int n, m;
  cin >> n >> m;
  map<pii, char> colour;
  set<pii> cycles, same;
  while (m--) {
    string op;
    cin >> op;
    if (op[0] == '+') {
      int u, v;
      string c;
      cin >> u >> v >> c;
      colour[mp(u, v)] = c[0];
      if (colour.count(mp(v, u))) {
        int x = u, y = v;
        if (x > y) swap(x, y);
        cycles.emplace(x, y);
        if (colour[mp(v, u)] == c[0]) same.emplace(x, y);
      }
    } else if (op[0] == '-') {
      int u, v;
      cin >> u >> v;
      colour.erase(mp(u, v));
      if (u > v) swap(u, v);
      cycles.erase(mp(u, v)); same.erase(mp(u, v));
    } else {
      int k; cin >> k;
      if (cycles.empty()) {
        cout << "NO\n";
        continue;
      }
      if (k % 2 == 0 && same.empty()) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
    }
  }
}