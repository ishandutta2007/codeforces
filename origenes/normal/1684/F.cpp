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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), L(n + 1, n + 1), f(n + 1, n + 1);
  map<int, vector<int>> pos;
  FOR(i, 1, n) {
    cin >> a[i];
    pos[a[i]].eb(i);
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    chkmin(L[r], l);
  }
  int nowl = n, en = 1, mx = n + 1;
  ROF(i, n, 1) {
    chkmin(nowl, L[i]);
    pos[a[i]].pop_back();
    if (nowl < i) {
      int last = pos[a[i]].empty() ? -1 : pos[a[i]].back();
      if (last >= nowl) {
        chkmax(en, last);
        auto it = lower_bound(all(pos[a[i]]), nowl), it2 = it;
        it2++;
        if (it2 == pos[a[i]].end()) chkmin(mx, i);
        else chkmin(mx, *it2);
        chkmin(f[i - 1], *it);
      }
    }
  }
  int ans = n;
  ROF(i, n, en) {
    chkmin(mx, f[i]);
    chkmin(ans, max(0, i - mx + 1));
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}