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
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  a.eb(-1e15); a.eb(1e15);
  sort(all(a));
  vector<pii> segs(m);
  for (auto &[l, r] : segs) cin >> l >> r;
  {
    vector<pii> tmp;
    for (auto [l, r] : segs) {
      auto it1 = lower_bound(all(a), l);
      auto it2 = lower_bound(all(a), r + 1);
      if (it1 == it2) tmp.eb(l, r);
    }
    sort(all(tmp), [](pii a, pii b) { return a._1 == b._1 ? a._2 > b._2 : a._1 < b._1; });
    segs.clear();
    for (auto [l, r] : tmp) {
      while (!segs.empty() && segs.back()._2 >= r) segs.pop_back();
      segs.eb(l, r);
    }
    m = segs.size();
  }
  int pos = 0;
  vector<pii> nxt;
  while (pos < m && segs[pos]._2 < a[1]) nxt.eb(segs[pos++]);
  vector<ll> pf(pos + 1, 1e18); pf[0] = 0;
  FOR(i, 1, n) {
    auto pre = nxt;
    nxt.clear();
    while (pos < m && segs[pos]._2 < a[i + 1]) nxt.eb(segs[pos++]);
    vector<ll> f(nxt.size() + 1, 1e18);
    set<ll> twos, ones;
    pre.eb(a[i], a[i]);
    REP(pj, pre.size()) ones.emplace(pf[pj] + a[i] - pre[pj]._2);
    f[0] = *ones.begin();
    int pj = int(pre.size()) - 1;
    REP(j, int(nxt.size())) {
      while (pj >= 0 && a[i] - pre[pj]._2 <= nxt[j]._1 - a[i]) {
        twos.emplace(pf[pj] + 2 * (a[i] - pre[pj]._2));
        ones.erase(pf[pj] + a[i] - pre[pj]._2);
        pj--;
      }
      if (!ones.empty()) chkmin(f[j + 1], 2 * (nxt[j]._1 - a[i]) + *ones.begin());
      chkmin(f[j + 1], nxt[j]._1 - a[i] + *twos.begin());
    }
    swap(pf, f);
  }
  cout << pf.back() << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}