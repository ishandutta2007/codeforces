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

struct Node {
  int l, r;
  int mx, mn, ans, len;
} T[(1 << 20) + 5];

int n, k, now;
int cnt[1 << 19], ans[1 << 19];

void maintain(int o) {
  T[o].len = T[T[o].l].len + T[T[o].r].len;
  T[o].mx = max(T[T[o].l].mx, T[T[o].r].mx + T[T[o].l].len);
  T[o].mn = min(T[T[o].l].mn, T[T[o].r].mn + T[T[o].l].len);
  T[o].ans = min(min(T[T[o].l].ans, T[T[o].r].ans), int(1e9));
  chkmin(T[o].ans, T[T[o].r].mn - T[T[o].l].mx + T[T[o].l].len);
}

void build(int o, int l, int r) {
  if (l == r) {
    T[o].ans = 1e9;
    T[o].len = 1;
    if (cnt[l] != 1) {
      T[o].mx = -1e9;
      T[o].mn = 1e9;
    }
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    T[o].l = o << 1; T[o].r = o << 1 | 1;
    maintain(o);
  }
}

void dfs(int o, int d) {
  if (d == 0) swap(T[o].l, T[o].r);
  else {
    dfs(T[o].l, d - 1);
    dfs(T[o].r, d - 1);
  }
  maintain(o);
}

void dfs(int d) {
  if (d == 0) ans[now] = T[1].ans;
  else dfs(d - 1);
  dfs(1, d);
  now ^= 1 << k - d - 1;
  if (d == 0) ans[now] = T[1].ans;
  else dfs(d - 1);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  REP(i, n) {
    int x; cin >> x;
    cnt[x]++;
  }
  build(1, 0, (1 << k) - 1);
  dfs(k - 1);
  REP(i, 1 << k) cout << ans[i] << ' ';
}