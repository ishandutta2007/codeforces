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

struct Seg {
  int l, r;
  int mx, mn, lzy;
  ll sum;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void push_down(int o) {
  T[o << 1].mx += T[o].lzy; T[o << 1].mn += T[o].lzy;
  T[o << 1].sum += (T[o << 1].r - T[o << 1].l + 1) * ll(T[o].lzy); T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].mx += T[o].lzy; T[o << 1 | 1].mn += T[o].lzy;
  T[o << 1 | 1].sum += (T[o << 1 | 1].r - T[o << 1 | 1].l + 1) * ll(T[o].lzy); T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
  T[o].mn = min(T[o << 1].mn, T[o << 1 | 1].mn);
  T[o].sum = T[o << 1].sum + T[o << 1 | 1].sum;
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx += v; T[o].mn += v;
    T[o].lzy += v;
    T[o].sum += (T[o].r - T[o].l + 1) * ll(v);
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

void update(int o, int l, int r, int v) {
  if (T[o].mn >= v) return;
  if (l <= T[o].r && T[o].r <= r) {
    if (T[o].mx <= v) {
      T[o].mx = T[o].mn = v;
      T[o].lzy = 0;
      T[o].sum = (T[o].r - T[o].l + 1) * ll(T[o].mx);
      return;
    }
    push_down(o);
    update(o << 1, l, r, v);
    update(o << 1 | 1, l, r, v);
    push_up(o);
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  push_up(o);
}

char s[maxn];
int n;

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  build(1, 1, n);
  int l = 0;
  ll ans = 0;
  FOR(i, 1, n) {
    if (s[i] == '0') {
      l = 0;
    } else if (l == 0) {
      add(1, i, i, 1);
      if (i - 1 >= 1) update(1, 1, i - 1, 1);
      l = i;
    } else {
      add(1, l, i, 1);
      if (l - 1 >= 1) update(1, 1, l - 1, i - l + 1);
    }
    ans += T[1].sum;
  }
  printf("%lld", ans);
}