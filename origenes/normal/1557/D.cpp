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

const int maxn = 312345;

struct Seg {
  int l, r;
  bool lzy;
  pii v;
} T[maxn << 3];

vector<pii> G[maxn];
int nxt[maxn];
bool ans[maxn];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].v = {0, -1};
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void push_down(int o) {
  if (T[o].lzy) {
    T[o << 1].v = T[o << 1 | 1].v = T[o].v;
    T[o << 1].lzy = T[o << 1 | 1].lzy = true;
    T[o].lzy = false;
  }
}

pii query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].v;
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  pii ret = {0, -1};
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  return ret;
}

void update(int o, int l, int r, pii v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy = true;
    T[o].v = v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  T[o].v = max(T[o << 1].v, T[o << 1 | 1].v);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> tmp;
  FOR(i, 1, m) {
    int id, l, r;
    cin >> id >> l >> r;
    G[id].eb(l, r);
    tmp.eb(l); tmp.eb(r);
  }
  sort(all(tmp)); uni(tmp);
  auto loc = [&](int x) {
    return lower_bound(all(tmp), x) - tmp.begin() + 1;
  };
  FOR(i, 1, n) for (auto &[x, y] : G[i]) {
    x = loc(x);
    y = loc(y);
  }
  build(1, 1, tmp.size());
  FOR(i, 1, n) {
    pii cur = {0, -1};
    for (auto [l, r] : G[i]) chkmax(cur, query(1, l, r));
    nxt[i] = cur._2;
    cur._1++, cur._2 = i;
    for (auto [l, r] : G[i]) update(1, l, r, cur);
  }
  pii mx = query(1, 1, tmp.size());
  cout << n - mx._1 << '\n';
  for (int i = mx._2; i != -1; i = nxt[i]) ans[i] = true;
  FOR(i, 1, n) if (!ans[i]) cout << i << ' ';
}