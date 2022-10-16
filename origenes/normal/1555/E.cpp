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
  int l, r;
  int lzy, mn;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l != r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void push_down(int o) {
  T[o << 1].lzy += T[o].lzy; T[o << 1].mn += T[o].lzy;
  T[o << 1 | 1].lzy += T[o].lzy; T[o << 1 | 1].mn += T[o].lzy;
  T[o].lzy = 0;
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy += v;
    T[o].mn += v;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  T[o].mn = min(T[o << 1].mn, T[o << 1 | 1].mn);
}

vector<pii> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  build(1, 1, m - 1);
  while (n--) {
    int l, r, w;
    cin >> l >> r >> w;
    G[w].eb(l, r - 1);
  }
  int ans = 1e9, mx = 0;
  FOR(i, 1, 1e6) {
    while (!T[1].mn && mx < 1e6) {
      mx++;
      for (auto [l, r] : G[mx]) add(1, l, r, 1);
    }
    if (!T[1].mn) break;
    chkmin(ans, mx - i);
    for (auto [l, r] : G[i]) add(1, l, r, -1);
  }
  cout << ans;
}