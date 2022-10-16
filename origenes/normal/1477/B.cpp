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
  int lzy, sum;

  int len() {
    return r - l + 1;
  }
} T[maxn << 2];

int n, q;
string s, f;

void push_down(int o) {
  if (T[o].lzy == -1) return;
  T[o << 1].lzy = T[o].lzy; T[o << 1].sum = T[o << 1].lzy * T[o << 1].len();
  T[o << 1 | 1].lzy = T[o].lzy; T[o << 1 | 1].sum = T[o << 1 | 1].lzy * T[o << 1 | 1].len();
  T[o].lzy = -1;
}

void push_up(int o) {
  T[o].sum = T[o << 1].sum + T[o << 1 | 1].sum;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].lzy = -1;
    T[o].sum = f[l] == '1';
  } else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    T[o].lzy = -1;
    push_up(o);
  }
}

void update(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy = v;
    T[o].sum = v * T[o].len();
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].sum;
  int mi = T[o].l + T[o].r >> 1, ret = 0;
  push_down(o);
  if (l <= mi) ret += query(o << 1, l, r);
  if (r > mi) ret += query(o << 1 | 1, l, r);
  return ret;
}

void solve() {
  cin >> n >> q;
  cin >> s >> f;
  build(1, 0, n - 1);
  vector<pii> queries(q);
  REP(i, q) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    queries[i] = {l, r};
  }
  reverse(all(queries));
  for (auto [l, r] : queries) {
    int len = r - l + 1, ones = query(1, l, r);
    if (ones > len / 2) update(1, l, r, 1);
    else if (len - ones > len / 2) update(1, l, r, 0);
    else {
      cout << "NO\n";
      return;
    }
  }
  REP(i, n) if (query(1, i, i) != s[i] - '0') {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}