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

const int maxn = 212345;

struct Seg {
  int l, r;
  ll mn, lzy;
} T[maxn << 2];

int n;
int p[maxn], pos[maxn], a[maxn];
ll s[maxn];

void push_down(int o) {
  T[o << 1].mn += T[o].lzy;
  T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].mn += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].mn = min(T[o << 1].mn, T[o << 1 | 1].mn);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].mn = s[l];
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mn += v;
    T[o].lzy += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) s[i] = s[i - 1] + a[i];
  FOR(i, 1, n) pos[p[i]] = i;
  build(1, 1, n - 1);
  ll ans = T[1].mn;
  FOR(i, 1, n) {
    if (pos[i] != 1) add(1, 1, pos[i] - 1, a[pos[i]]);
    if (pos[i] != n) add(1, pos[i], n - 1, -a[pos[i]]);
    chkmin(ans, T[1].mn);
  }
  printf("%lld", ans);
}