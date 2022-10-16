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

const int MOD = 998244353;
const int maxn = 212345;
const int i100 = 828542813;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int inv(int x) {
  int pw = MOD - 2, ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, x);
    x = mul(x, x);
    pw >>= 1;
  }
  return ret;
}

int p[maxn], ip[maxn], pre[maxn], nxt[maxn], n, q, ans;
int sum[maxn][18];
bool cpt[maxn];

int prod(int l, int r) {
  if (r == l - 1) return 1;
  return mul(p[r], ip[l - 1]);
}

int f(int l, int r) {
  int Q = prod(l, r - 1);
  int P = 0;
  int st = l;
  ROF(i, 17, 0) if (st + (1 << i) - 1 <= r - 2) {
    P = add(P, mul(prod(l, st - 1), sum[st][i]));
    st += 1 << i;
  }
  P = add(P, 1);
  return mul(P, inv(Q));
}

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) {
    scanf("%d", p + i);
    p[i] = mul(p[i], i100);
  }
  p[0] = ip[0] = 1;
  FOR(i, 1, n) sum[i][0] = p[i];
  FOR(i, 1, n) p[i] = mul(p[i], p[i - 1]), ip[i] = inv(p[i]);
  FOR(j, 1, 17) for (int i = 1; i + (1 << j) - 1 <= n; i++)
    sum[i][j] = add(sum[i][j - 1], mul(sum[i + (1 << j - 1)][j - 1], prod(i, i + (1 << j - 1) - 1)));
  cpt[1] = cpt[n + 1] = true;
  pre[n + 1] = 1; nxt[1] = n + 1;
  ans = f(1, n + 1);
  set<int> cur; cur.emplace(1), cur.emplace(n + 1);
  while (q--) {
    int u; scanf("%d", &u);
    if (cpt[u]) {
      int a = pre[u], b = nxt[u];
      ans = add(ans, MOD - f(a, u));
      ans = add(ans, MOD - f(u, b));
      cpt[u] = false, nxt[a] = b, pre[b] = a, cur.erase(u);
      ans = add(ans, f(a, b));
    } else {
      int b = *cur.lower_bound(u), a = pre[b];
      ans = add(ans, MOD - f(a, b));
      cpt[u] = true, nxt[a] = u, pre[b] = u, pre[u] = a, nxt[u] = b, cur.emplace(u);
      ans = add(ans, f(a, u));
      ans = add(ans, f(u, b));
    }
    printf("%d\n", ans);
  }
}