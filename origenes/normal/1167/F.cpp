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

const int maxn = 512345;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, ans;

inline int lowbit(int x) {
  return x & -x;
}

void upd(int *fen, int x, int v) {
  while (x <= n) {
    fen[x] = add(fen[x], v);
    x += lowbit(x);
  }
}

int query(const int *fen, int x) {
  int ret = 0;
  while (x > 0) {
    ret = add(ret, fen[x]);
    x -= lowbit(x);
  }
  return ret;
}

int get(const int *fen, int lo, int hi) {
  return add(query(fen, hi), MOD - query(fen, lo - 1));
}

int fen[2][maxn], a[maxn], id[maxn];

int main() {
  scanf("%d", &n);
  set<pii> s;
  FOR(i, 1, n) {
    scanf("%d", a + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] < a[y];});
  FOR(i, 1, n) {
    upd(fen[0], id[i], id[i]);
    upd(fen[1], id[i], n - id[i] + 1);
    int now = mul(n - id[i] + 1, get(fen[0], 1, id[i] - 1));
    now = add(now, mul(id[i], get(fen[1], id[i] + 1, n)));
    now = add(now, mul(id[i], n - id[i] + 1));
    ans = add(ans, mul(now, a[id[i]]));
  }
  printf("%d", ans);
}