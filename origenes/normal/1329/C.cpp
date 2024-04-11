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

const int maxn = 2123456;

int h, g;
int a[maxn];

int check(int u) {
  if (!a[u << 1] && !a[u << 1 | 1]) return u;
  if (a[u << 1] > a[u << 1 | 1]) return check(u << 1);
  return check(u << 1 | 1);
}

void dfs(int u) {
  if (!a[u << 1] && !a[u << 1 | 1]) a[u] = 0;
  else if (a[u << 1] > a[u << 1 | 1]) {
    a[u] = a[u << 1];
    dfs(u << 1);
  } else {
    a[u] = a[u << 1 | 1];
    dfs(u << 1 | 1);
  }
}

void solve() {
  scanf("%d%d", &h, &g);
  fill(a + 1, a + (1 << h + 1), 0);
  FOR(i, 1, (1 << h) - 1) scanf("%d", a + i);
  vector<int> ans; ans.reserve(1 << g);
  FOR(i, 1, (1 << g) - 1) while (check(i) >= 1 << g) {
    ans.eb(i);
    dfs(i);
  }
  ll s = 0;
  FOR(i, 1, (1 << g) - 1) s += a[i];
  printf("%lld\n", s);
  for (auto x : ans) printf("%d ", x);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}