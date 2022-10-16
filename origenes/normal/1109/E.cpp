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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;
const int maxm = 1712345;

struct Seg {
  int l, r, val, lzy;
  vector<int> cnt;

  int get();
} T[maxn << 2];

vector<int> lis, cnt;
vector<vector<int>> pw;

int n, MOD, sz, q;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int Seg::get() {
  int ret = mul(val, lzy);
  REP(i, sz) ret = mul(ret, pw[i][cnt[i]]);
  return ret;
}

int a[maxn];
bool vis[maxn];
vector<int> primes;

inline void push_up(int o) {
  T[o].val = add(T[o << 1].get(), T[o << 1 | 1].get());
}

inline void push_down(int o) {
  REP(i, sz) {
    T[o << 1].cnt[i] += T[o].cnt[i];
    T[o << 1 | 1].cnt[i] += T[o].cnt[i];
    T[o].cnt[i] = 0;
  }
  T[o << 1].lzy = mul(T[o << 1].lzy, T[o].lzy);
  T[o << 1 | 1].lzy = mul(T[o << 1 | 1].lzy, T[o].lzy);
  T[o].lzy = 1;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r, T[o].lzy = 1;
  T[o].cnt.resize(sz);
  if (l == r) {
    REP(i, sz) while (a[l] % lis[i] == 0) {
        T[o].cnt[i]++;
        a[l] /= lis[i];
      }
    T[o].val = a[l] % MOD;
    return;
  }
  int mi = l + r >> 1;
  build(o << 1, l, mi);
  build(o << 1 | 1, mi + 1, r);
  push_up(o);
}

void mul(int o, int l, int r, int x, const vector<int> &vec) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy = mul(T[o].lzy, x);
    REP(i, sz) T[o].cnt[i] += vec[i];
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) mul(o << 1, l, r, x, vec);
  if (r > mi) mul(o << 1 | 1, l, r, x, vec);
  push_up(o);
}

void div(int o, int p, int ix, const vector<int> &vec) {
  if (T[o].l == T[o].r) {
    REP(i, sz) T[o].cnt[i] -= vec[i];
    T[o].val = mul(T[o].val, ix);
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (p <= mi) div(o << 1, p, ix, vec);
  else div(o << 1 | 1, p, ix, vec);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].get();
  int mi = T[o].l + T[o].r >> 1, ret = 0;
  push_down(o);
  if (l <= mi) ret = add(ret, query(o << 1, l, r));
  if (r > mi) ret = add(ret, query(o << 1 | 1, l, r));
  push_up(o);
  return ret;
}

void init() {
  int upp = sqrt(MOD) + 0.5;
  FOR(i, 2, upp) if (!vis[i]) {
      primes.eb(i);
      for (int j = i; j <= upp; j += i) vis[j] = true;
    }
  int tmp = MOD;
  for (auto it : primes) if (tmp % it == 0) {
      lis.eb(it);
      cnt.eb(0);
      while (tmp % it == 0) cnt.back()++, tmp /= it;
    }
  if (tmp != 1) lis.eb(tmp), cnt.eb(1);
  sz = lis.size();
  pw = vector<vector<int>>(sz, vector<int>(maxm));
  REP(i, sz) {
    pw[i][0] = 1;
    FOR(j, 1, maxm - 1000) pw[i][j] = mul(pw[i][j - 1], lis[i]);
  }
}

void exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= x * (a / b);
}

int inv(int a) {
  int x, y;
  exgcd(a, MOD, x, y);
  return (x + MOD) % MOD;
}

int main() {
  scanf("%d%d", &n, &MOD);
  FOR(i, 1, n) scanf("%d", a + i);
  init();
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      vector<int> vec(sz);
      REP(i, sz) while (x % lis[i] == 0) vec[i]++, x /= lis[i];
      mul(1, l, r, x % MOD, vec);
    } else if (op == 2) {
      int p, x;
      scanf("%d%d", &p, &x);
      vector<int> vec(sz);
      REP(i, sz) while (x % lis[i] == 0) vec[i]++, x /= lis[i];
      x = inv(x % MOD);
      div(1, p, x, vec);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(1, l, r));
    }
  }
}