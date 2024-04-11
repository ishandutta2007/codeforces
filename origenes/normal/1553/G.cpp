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

const int maxn = 151234;
const int maxa = 1123456;

int n, q;
int a[maxn], par[maxa];
vector<int> G[maxa];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  par[x] = y;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 2, 1e6 + 1) if (G[i].empty()) for (int j = i; j <= 1e6 + 1; j += i) G[j].eb(i);
  iota(par + 1, par + int(1e6) + 2, 1);
  FOR(i, 1, n) for (auto p : G[a[i]]) Union(p, a[i]);
  set<pii> ones;
  FOR(i, 1, n) {
    auto now = G[a[i] + 1];
    now.eb(a[i]);
    for (auto &x : now) x = Find(x);
    REP(x, now.size()) FOR(y, x + 1, int(now.size()) - 1) {
      int u = now[x], v = now[y];
      if (u > v) swap(u, v);
      if (u != v) ones.emplace(u, v);
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    s = Find(a[s]), t = Find(a[t]);
    if (s > t) swap(s, t);
    if (s == t) cout << 0;
    else if (ones.count(mp(s, t))) cout << 1;
    else cout << 2;
    cout << '\n';
  }
}