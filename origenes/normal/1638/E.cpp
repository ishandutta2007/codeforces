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

const int maxn = 1123456;

struct Seg {
  int l, r, c;
  ll v;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  } else T[o].c = 1;
}

int get_c(int o, int x) {
  if (T[o].c) return T[o].c;
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) return get_c(o << 1, x);
  return get_c(o << 1 | 1, x);
}

void upd_c(int o, int l, int r, int c) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].c = c;
    return;
  }
  if (T[o].c) {
    T[o << 1].c = T[o].c;
    T[o << 1 | 1].c = T[o].c;
    T[o].c = 0;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) upd_c(o << 1, l, r, c);
  if (r > mi) upd_c(o << 1 | 1, l, r, c);
}

ll get_v(int o, int x) {
  if (T[o].l == T[o].r) return T[o].v;
  int mi = T[o].l + T[o].r >> 1;
  return T[o].v + get_v(o << 1 | (x > mi), x);
}

void upd_v(int o, int l, int r, ll v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) upd_v(o << 1, l, r, v);
  if (r > mi) upd_v(o << 1 | 1, l, r, v);
}

set<pii> intervals[maxn];
ll d[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q;
  cin >> n >> q;
  build(1, 1, n);
  intervals[1].emplace(1, n);
  while (q--) {
    string op;
    cin >> op;
    if (op == "Color") {
      int l, r, c;
      cin >> l >> r >> c;
      int pl = l, pr = r;
      while (l <= r) {
        int cp = get_c(1, l);
        auto it = intervals[cp].lower_bound(mp(l + 1, 0));
        --it;
        auto [cl, cr] = *it;
        intervals[cp].erase(it);
        if (cl < l) {
          intervals[cp].emplace(cl, l - 1);
          cl = l;
        }
        if (cr > r) {
          intervals[cp].emplace(r + 1, cr);
          cr = r;
        }
        upd_v(1, cl, cr, d[cp] - d[c]);
        it = intervals[c].lower_bound(mp(cl, cr));
        vector<decltype(it)> dels;
        if (it != intervals[c].begin()) {
          auto it2 = it; it2--;
          if (it2->_2 == cl - 1) {
            cl = it2->_1;
            dels.eb(it2);
          }
        }
        if (it != intervals[c].end()) {
          if (it->_1 == cr + 1) {
            cr = it->_2;
            dels.eb(it);
          }
        }
        for (auto x : dels) intervals[c].erase(mp(x->_1, x->_2));
        intervals[c].emplace(cl, cr);
        l = cr + 1;
      }
      upd_c(1, pl, pr, c);
    } else if (op == "Add") {
      int c, x;
      cin >> c >> x;
      d[c] += x;
    } else {
      int i; cin >> i;
      int c = get_c(1, i);
      cout << get_v(1, i) + d[c] << '\n';
    }
  }
}