#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

using ll = long long;
#define SZ(v) ((int)v.size())
struct LazyAddMax {
  vector<ll> seg;
  vector<ll> updates;
  int nb_elem;
  ll UNDEF = 1e18;
  int p, deb;

  LazyAddMax() {}

  LazyAddMax(const vector<ll> &arr) {
    p = 0;
    while ((1 << p) < SZ(arr))
      ++p;
    deb = (1 << p) - 1;
    nb_elem = (1 << p);
    seg.resize(4 * nb_elem);
    updates.resize(4 * nb_elem);
    for (int i(0); i < SZ(seg); ++i)
      seg[i] = UNDEF;
    for (int i(0); i < SZ(arr); ++i)
      seg[deb + i] = arr[i];
    for (int i(deb - 1); i >= 0; --i)
      seg[i] = min(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void push(int node) {
    seg[node] += updates[node];
    if (2 * node + 1 < SZ(updates))
      updates[2 * node + 1] += updates[node];
    if (2 * node + 2 < SZ(updates))
      updates[2 * node + 2] += updates[node];
    updates[node] = 0;
  }

  void __add(int node, int l, int r, int lo, int up, ll delta) {
    if (l > r)
      return;
    push(node);
    if (l > up or r < lo)
      return;
    if (lo <= l and up >= r) {
      updates[node] += delta;
      push(node);
      return;
    }
    int mid = (l + r) / 2;
    __add(2 * node + 1, l, mid, lo, up, delta);
    __add(2 * node + 2, mid + 1, r, lo, up, delta);
    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
    assert(!updates[node]);
  }

  void add(int lo, int up, ll delta) {
    __add(0, 0, nb_elem - 1, lo, up, delta);
  }

  ll __query(int node, int l, int r, int lo, int up) {
    push(node);
    if (l > up or r < lo)
      return UNDEF;
    if (l >= lo and r <= up)
      return seg[node];
    return min(__query(2 * node + 1, l, (l + r) / 2, lo, up),
               __query(2 * node + 2, (l + r) / 2 + 1, r, lo, up));
  }

  ll query(int lo, int up) { return __query(0, 0, nb_elem - 1, lo, up); }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbSeg, nbPoints;
  cin >> nbSeg >> nbPoints;

  vector<tuple<int, int, int>> segments(nbSeg);
  for (auto &[l, r, w] : segments) {
    cin >> l >> r >> w;
    --l, --r;
  }
  sort(segments.begin(), segments.end(),
       [&](auto a, auto b) { return get<2>(a) < get<2>(b); });

  int ret = INF;
  vector<int> v(nbPoints, 0);
  LazyAddMax lazy(v);

  int r = 0;
  for (int l = 0; l < nbSeg; ++l) {
    r = max(r, l);
    while (r < nbSeg and !lazy.query(0, nbPoints - 2)) {
      lazy.add(get<0>(segments[r]), get<1>(segments[r]) - 1, 1);
      r++;
    }
    // cout << lazy.query(0, nbPoints - 2) << endl;
    if (!lazy.query(0, nbPoints - 2))
      break;
    ret = min(ret, get<2>(segments[r - 1]) - get<2>(segments[l]));
    lazy.add(get<0>(segments[l]), get<1>(segments[l]) - 1, -1);
  }

  cout << ret << endl;
}