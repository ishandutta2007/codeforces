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
  ll sum, lzy;

  int len() {
    return r - l + 1;
  }
} T[maxn << 3];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void push_down(int o) {
  T[o << 1].sum += T[o << 1].len() * T[o].lzy;
  T[o << 1 | 1].sum += T[o << 1 | 1].len() * T[o].lzy;
  T[o << 1].lzy += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].sum = T[o << 1].sum + T[o << 1 | 1].sum;
}

void update(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy += v;
    T[o].sum += T[o].len() * v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  push_up(o);
}

int get(int o, int k) {
  if (T[o].l == T[o].r) return T[o].sum >= k ? T[o].l : -1;
  push_down(o);
  if (T[o << 1].sum >= k) return get(o << 1, k);
  return get(o << 1 | 1, k - T[o << 1].sum);
}

int n, k;
int L[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> L[i];
  sort(L + 1, L + n + 1, greater<>());
  build(1, 0, 4e5);
  update(1, 0, 0, 1);
  int ans = -1;
  FOR(i, 1, n) {
    int l1 = (L[i] - 1) / 2, l2 = L[i] / 2;
    int x = get(1, 1);
    if (x == -1) break;
    update(1, x, x, -1);
    update(1, x + 2, x + 1 + l1, 1);
    update(1, x + 2, x + 1 + l2, 1);
    int now = get(1, k);
    if (now != -1) {
      if (ans == -1) ans = now;
      else chkmin(ans, now);
    }
  }
  cout << ans;
}