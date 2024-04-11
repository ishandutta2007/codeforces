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

const int maxn = 80;

int f[maxn][maxn], pre[maxn][maxn];
int n, k, id[maxn], a[maxn], b[maxn];

void solve() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d%d", a + i, b + i);
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [&](int i, int j) { return b[i] < b[j]; });
  reset(f, 0);
  int bi = 0, bj = 0;
  FOR(i, 1, n) REP(j, min(i + 1, k + 1)) {
    if (j != min(i, k)) {
      f[i][j] = f[i - 1][j] + (k - 1) * b[id[i]];
      pre[i][j] = j;
    }
    if (j && f[i][j] < f[i - 1][j - 1] + a[id[i]] + (j - 1) * b[id[i]]) {
      f[i][j] = f[i - 1][j - 1] + a[id[i]] + (j - 1) * b[id[i]];
      pre[i][j] = j - 1;
      if (j == k) {
        int s = 0;
        FOR(l, i + 1, n) s += (k - 1) * b[id[l]];
        if (f[i][j] + s > f[bi][bj]) {
          bi = i;
          bj = j;
          f[i][j] += s;
        }
      }
    }
  }
  int j = pre[bi][bj];
  stack<int> ans, sel;
  ans.emplace(id[bi]);
  ROF(l, n, bi + 1) {
    ans.emplace(-id[l]);
    ans.emplace(id[l]);
  }
  ROF(i, bi - 1, 1) {
    if (pre[i][j] == j) {
      ans.emplace(-id[i]);
      ans.emplace(id[i]);
    }
    else sel.emplace(id[i]);
    j = pre[i][j];
  }
  printf("%lu\n", ans.size() + sel.size());
  while (!sel.empty()) {
    printf("%d ", sel.top());
    sel.pop();
  }
  while (!ans.empty()) {
    printf("%d ", ans.top());
    ans.pop();
  }
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}