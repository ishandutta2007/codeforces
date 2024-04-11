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

map<int, int> cnt[2];
int n, m, st[2];

ll C2(ll x) {
  return x * (x - 1) / 2;
}

ll C3(ll x) {
  return x * (x - 1) / 2 * (x - 2) / 3;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  REP(i, m) {
    int x, y; cin >> x >> y;
    st[x]++;
    cnt[x][y]++;
  }
  int best = 0;
  ll ans = 0;
  REP(i, 2) if (!cnt[i].empty()) {
    int mi = 2 * (cnt[i].rbegin()->_1 - cnt[i].begin()->_1);
    int occ[2] = {cnt[i].rbegin()->_2, cnt[i].begin()->_2};
    ll now = 0;
    if (mi) now = C2(occ[0]) * occ[1] + C2(occ[1]) * occ[0] + ll(occ[0]) * occ[1] * (m - occ[0] - occ[1]);
    else now = C3(occ[0]);
    if (best < mi) best = mi;
    if (best == mi) ans = now;
  }
  REP(i, 2) if (!cnt[i].empty()) {
    int l = cnt[i].begin()->_1, r = cnt[i].rbegin()->_1;
    bool f = false;
    for (auto [k, _] : cnt[1 - i]) if (l <= k && k <= r) {
      f = true;
      break;
    }
    if (f) {
      if (2 * n > best) {
        best = 2 * n;
        ans = 0;
      }
      auto it = cnt[i].begin();
      int acc = 0;
      for (auto [x, y] : cnt[1 - i]) {
        while (it != cnt[i].end() && it->_1 < x) {
          acc += it->_2;
          it++;
        }
        if (it != cnt[i].end() && it->_1 == x) ans += it->_2 * ll(st[i] - acc - it->_2) * y + C2(it->_2) * y;
        ans += ll(acc) * (st[i] - acc) * y;
      }
    } else {
      auto it1 = cnt[1 - i].lower_bound(r), it2 = cnt[1 - i].lower_bound(l);
      if (it2 != cnt[1 - i].begin()) {
        it2--;
        if (2 * n - 2 * (l - it2->_1) > best) {
          best = 2 * n - 2 * (l - it2->_1);
          ans = 0;
        }
        if (2 * n - 2 * (l - it2->_1) == best)
          ans += it2->_2 * C2(cnt[i].begin()->_2) + ll(it2->_2) * cnt[i].begin()->_2 * (st[i] - cnt[i].begin()->_2);
      }
      if (it1 != cnt[1 - i].end()) {
        if (2 * n - 2 * (it1->_1 - r) > best) {
          best = 2 * n - 2 * (it1->_1 - r);
          ans = 0;
        }
        if (2 * n - 2 * (it1->_1 - r) == best)
          ans += it1->_2 * C2(cnt[i].rbegin()->_2) + ll(it1->_2) * cnt[i].rbegin()->_2 * (st[i] - cnt[i].rbegin()->_2);
      }
    }
  }
  cout << ans;
}