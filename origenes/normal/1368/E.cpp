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

int n, m;
int f[maxn];
vector<int> G[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    G[i].clear();
    f[i] = 0;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[v].eb(u);
  }
  vector<int> ans;
  FOR(i, 1, n) {
    for (auto j : G[i]) chkmax(f[i], f[j] + 1);
    if (f[i] == 2) {
      f[i] = -1;
      ans.eb(i);
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%d ", x);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}