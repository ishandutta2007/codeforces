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

const int maxn = 112345;
const int BLK = 320;

inline bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
  ll u = (b._2 - a._2) * (c._1 - b._1);
  ll v = ll(b._2 - c._2) * (a._1 - b._1);
  return u > v;
}

struct Hull {
  deque<pair<ll, ll>> q;

  void add(ll k, ll b) {
    while (q.size() > 1 && !check(q[q.size() - 2], q.back(), {k, b})) q.pop_back();
    q.eb(k, b);
  }

  pair<ll, ll> query(ll x) {
    while (q.size() > 1 && q[0]._1 * x + q[0]._2 < q[1]._1 * x + q[1]._2) q.pop_front();
    return {q[0]._1 * x + q[0]._2, q[0]._1};
  }
} hull[BLK];

int n;
ll w, f[maxn];
int lzy[BLK], l[BLK], r[BLK];
vector<int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> w;
  int mx = 0;
  FOR(i, 1, n) {
    int a, b;
    cin >> a >> b;
    chkmax(mx, b);
    G[b].eb(a);
  }
  for (int i = 0; i * BLK <= 1e5; i++) {
    l[i] = i * BLK, r[i] = min(i * BLK + BLK - 1, 100000);
    FOR(j, l[i], r[i]) hull[i].add(j, 0);
  }
  ll tot = n;
  REP(c, mx + 2) {
    pair<ll, ll> ans;
    for (int i = 0; i * BLK <= 1e5; i++) chkmax(ans, hull[i].query(lzy[i]));
    cout << tot * c * w + ans._1 << ' ' << ans._2 << '\n';
    tot -= G[c].size();
    for (auto a : G[c]) {
      int bid = a / BLK;
      REP(i, bid) lzy[i]++;
      FOR(j, l[bid], r[bid]) f[j] += lzy[bid] * ll(j);
      FOR(j, l[bid], a) f[j] += j;
      hull[bid].q.clear();
      FOR(j, l[bid], r[bid]) hull[bid].add(j, f[j]);
      lzy[bid] = 0;
    }
  }
}