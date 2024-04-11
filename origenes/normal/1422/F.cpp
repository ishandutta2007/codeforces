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
const int MOD = 1e9 + 7;

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

struct Seg {
  int l, r;
  int cnt[88];
  vector<pii> pre;
  vector<int> prod;
} T[maxn << 2];

vector<int> primes;
map<int, int> last;
int n, q;
int a[maxn], rec[88], p[88][20];
bool vis[maxn];

void push_up(int o) {
  REP(i, 88) T[o].cnt[i] = max(T[o << 1].cnt[i], T[o << 1 | 1].cnt[i]);
  T[o].pre = T[o << 1].pre;
  for (auto x : T[o << 1 | 1].pre) T[o].pre.eb(x);
  sort(all(T[o].pre));
  T[o].prod.resize(T[o].pre.size());
  if (!T[o].pre.empty()) {
    T[o].prod[0] = T[o].pre[0]._2;
    FOR(i, 1, int(T[o].pre.size()) - 1) T[o].prod[i] = mul(T[o].prod[i - 1], T[o].pre[i]._2);
  }
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else {
    REP(i, 88) while (a[l] % primes[i] == 0) {
      a[l] /= primes[i];
      T[o].cnt[i]++;
    }
    if (a[l] != 1) {
      T[o].pre.eb(last[a[l]], a[l]);
      T[o].prod.eb(a[l]);
      last[a[l]] = l;
    }
  }
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) {
    REP(i, 88) chkmax(rec[i], T[o].cnt[i]);
    int pos = lower_bound(all(T[o].pre), mp(l, 0)) - T[o].pre.begin();
    return pos ? T[o].prod[pos - 1] : 1;
  }
  int mi = T[o].l + T[o].r >> 1, ret = 1;
  if (l <= mi) ret = mul(ret, query(o << 1, l, r));
  if (r > mi) ret = mul(ret, query(o << 1 | 1, l, r));
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 2, 2e5) if (!vis[i]) {
    primes.eb(i);
    for (int j = i + i; j <= 2e5; j += i) vis[j] = true;
  }
  REP(i, 88) {
    p[i][0] = 1;
    FOR(j, 1, 19) p[i][j] = mul(p[i][j - 1], primes[i]);
  }
  build(1, 1, n);
  int ans = 0;
  scanf("%d", &q);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    l = (l + ans) % n + 1;
    r = (r + ans) % n + 1;
    if (l > r) swap(l, r);
    reset(rec, 0);
    ans = query(1, l, r);
    REP(i, 88) ans = mul(ans, p[i][rec[i]]);
    printf("%d\n", ans);
  }
}