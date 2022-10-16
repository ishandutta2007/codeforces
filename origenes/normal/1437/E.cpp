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

int n, k;
int a[maxn], b[maxn];

void solve() {
  cin >> n >> k;
  FOR(i, 1, n) {
    cin >> a[i];
    a[i] -= i;
  }
  vector<int> fixed(k);
  for (auto &x : fixed) cin >> x;
  FOR(i, 1, int(fixed.size()) - 1) if (a[fixed[i]] < a[fixed[i - 1]]) {
    cout << "-1";
    return;
  }
  a[0] = -1e9; a[n + 1] = 1.5e9;
  int ans = 0;
  vector<int> ver;
  ver.eb(0);
  for (auto x : fixed) ver.eb(x);
  ver.eb(n + 1);
  vector<int> f(n + 2);
  FOR(id, 1, int(ver.size()) - 1) {
    int l = ver[id - 1] + 1, r = ver[id] - 1;
    if (l > r) continue;
    set<int> st(a + l - 1, a + r + 2);
    map<int, int> mmap;
    int have = 0;
    for (auto x : st) mmap[x] = ++have;
    FOR(i, l - 1, r + 1) b[i] = mmap[a[i]];
    vector<int> fen(have + 1, 1e9);
    auto update = [&](int x, int v) {
      while (x <= have) {
        chkmin(fen[x], v);
        x += x & -x;
      }
    };
    auto query = [&](int x) {
      int ret = 1e9;
      while (x > 0) {
        chkmin(ret, fen[x]);
        x -= x & -x;
      }
      return ret;
    };
    update(b[l - 1], f[l - 1] - (l - 1));
    FOR(i, l, r) {
      f[i] = query(b[i]) + i - 1;
      update(b[i], f[i] - i);
    }
    ans += query(b[r + 1]) + r;
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T = 1;
  while (T--) solve();
}
/*
6 0
2 3 1 5 6 7
 */