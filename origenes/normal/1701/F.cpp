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

using Vector = array<ll, 3>;
using Matrix = array<Vector, 3>;

const int maxn = 212345;
const Matrix E = {Vector{1, 0, 0}, Vector{0, 1, 0}, Vector{0, 0, 1}};
const Matrix Op = {Vector{1, 0, 0}, Vector{1, 1, 0}, Vector{1, 2, 1}};
const Matrix iOp = {Vector{1, 0, 0}, Vector{-1, 1, 0}, Vector{1, -2, 1}};

Vector operator+(const Vector &lhs, const Vector &rhs) {
  Vector ret = {};
  REP(i, 3) ret[i] = lhs[i] + rhs[i];
  return ret;
}

Vector operator*(const Matrix &m, const Vector &v) {
  Vector ret = {};
  REP(i, 3) REP(j, 3) ret[i] += m[i][j] * v[j];
  return ret;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
  Matrix ret = {};
  REP(i, 3) REP(j, 3) REP(k, 3) ret[i][j] += lhs[i][k] * rhs[k][j];
  return ret;
}

struct Seg {
  int l, r;
  Matrix mat;
  Vector v;
  bool on;
} T[maxn << 2];

Vector query(int o) {
  if (!T[o].on) return {0, 0, 0};
  return T[o].mat * T[o].v;
}

void push_up(int o) {
  T[o].v = query(o << 1) + query(o << 1 | 1);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].mat = E;
  if (l == r) {
    T[o].on = false;
    T[o].v = {1, 0, 0};
    return;
  }
  int mi = l + r >> 1;
  build(o << 1, l, mi);
  build(o << 1 | 1, mi + 1, r);
  push_up(o);
  T[o].on = true;
}

void push_down(int o) {
  if (T[o].mat != E) {
    T[o].v = T[o].mat * T[o].v;
    T[o << 1].mat = T[o].mat * T[o << 1].mat;
    T[o << 1 | 1].mat = T[o].mat * T[o << 1 | 1].mat;
    T[o].mat = E;
  }
}

void toggle(int o, int x) {
  if (T[o].l == T[o].r) {
    T[o].on ^= true;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) toggle(o << 1, x);
  else toggle(o << 1 | 1, x);
  push_up(o);
}

void update(int o, int l, int r, bool inc) {
  if (l <= T[o].l && T[o].r <= r) {
    if (inc) T[o].mat = Op * T[o].mat;
    else T[o].mat = iOp * T[o].mat;
    return;
  }
  push_up(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r, inc);
  if (r > mi) update(o << 1 | 1, l, r, inc);
  push_up(o);
}

bool have[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int q, d;
  cin >> q >> d;
  build(1, 1, 2e5);
  while (q--) {
    int a; cin >> a;
    int l = max(a - d, 1), r = a - 1;
    if (l <= r) update(1, l, r, !have[a]);
    toggle(1, a);
    have[a] = !have[a];
    auto v = query(1);
    cout << (v[2] - v[1]) / 2 << '\n';
  }
}