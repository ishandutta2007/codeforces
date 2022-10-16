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

const int maxn = 112345;

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

int n;
ll a[maxn], mx[maxn], cnt[maxn], ans;
vector<int> G[maxn];

void dfs(int u, int par) {
  int ch = 0;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    if (!ch) {
      mx[u] = mx[v];
      cnt[u] = cnt[v];
    } else {
      if (cnt[u] < 2e13) cnt[u] = lcm(cnt[u], cnt[v]);
      mx[u] = min(mx[u], mx[v]) / cnt[u] * cnt[u];
    }
    ch++;
  }
  if (!ch) {
    cnt[u] = 1;
    mx[u] = a[u];
  } else {
    mx[u] *= ch;
    if (cnt[u] < 2e13) cnt[u] *= ch;
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%lld", a + i);
    ans += a[i];
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  printf("%lld", ans - mx[1]);
}