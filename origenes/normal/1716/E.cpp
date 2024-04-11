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

const int maxn = 1 << 18;

struct Seg {
  struct Value {
    ll v = -1, pre, suf, sum;
  };
  vector<Value> vals;
} T[maxn << 2];

Seg::Value operator+(const Seg::Value &s1, const Seg::Value &s2) {
  Seg::Value ret;
  ret.v = max({s1.v, s2.v, s1.suf + s2.pre});
  ret.pre = max(s1.pre, s1.sum + s2.pre);
  ret.suf = max(s1.suf + s2.sum, s2.suf);
  ret.sum = s1.sum + s2.sum;
  return ret;
}

int a[maxn];

void build(int o, int l, int r) {
  if (l == r) {
    T[o].vals.resize(1);
    T[o].vals[0].v = T[o].vals[0].pre = T[o].vals[0].suf = max(a[l], 0);
    T[o].vals[0].sum = a[l];
    return;
  }
  int mi = l + r >> 1;
  build(o << 1, l, mi);
  build(o << 1 | 1, mi + 1, r);
  T[o].vals = vector<Seg::Value>(r - l + 1);
  T[o].vals[0] = T[o << 1].vals[0] + T[o << 1 | 1].vals[0];
}

Seg::Value query(int o, int mask, int i) {
  if (T[o].vals[mask].v != -1) return T[o].vals[mask];
  if (mask & (1 << i))
    return T[o].vals[mask] = query(o << 1 | 1, mask ^ (1 << i), i - 1) + query(o << 1, mask ^ (1 << i), i - 1);
  return T[o].vals[mask] = query(o << 1, mask, i - 1) + query(o << 1 | 1, mask, i - 1);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  REP(i, 1 << n) cin >> a[i];
  build(1, 0, (1 << n) - 1);
  int mask = 0, q;
  cin >> q;
  while (q--) {
    int k; cin >> k;
    mask ^= 1 << k;
    cout << query(1, mask, n - 1).v << '\n';
  }
}