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

const int maxn = 112345;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, m;
int deg[maxn << 1], val[maxn << 1], pw[maxn], f[maxn];
vector<int> G[maxn];

int main() {
  scanf("%d%d", &n, &m);
  pw[0] = 1;
  FOR(i, 1, n - 1) pw[i] = mul(pw[i - 1], n);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    if (u > v) swap(u, v);
    G[u].eb(v - u);
    G[v].eb(n - v + u);
  }
  REP(i, n) {
    deg[i] = G[i].size();
    sort(all(G[i]));
    for (auto it : G[i]) val[i] = add(val[i], pw[it]);
  }
  memcpy(deg + n, deg, n * sizeof(int));
  memcpy(val + n, val, n * sizeof(int));
  FOR(i, 1, n - 1) {
    int j = f[i];
    while (j && (deg[i] != deg[j] || val[i] != val[j])) j = f[j];
    f[i + 1] = deg[i] == deg[j] && val[i] == val[j] ? j + 1 : 0;
  }
  int j = 0;
  FOR(i, 1, 2 * n - 1) {
    while (j && (deg[i] != deg[j] || val[i] != val[j])) j = f[j];
    if (deg[i] == deg[j] && val[i] == val[j]) j++;
    if (j == n) {
      puts(i - n + 1 == n ? "No" : "Yes");
      return 0;
    }
  }
  puts("No");
}