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

int n;
int p[maxn], c[maxn];
bool vis[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, n) scanf("%d", c + i);
  fill(vis + 1, vis + n + 1, false);
  int ans = 1e9;
  FOR(i, 1, n) if (!vis[i]) {
    vector<int> cc;
    while (!vis[i]) {
      cc.eb(c[i]);
      vis[i] = true;
      i = p[i];
    }
    FOR(j, 1, int(cc.size()) + 1) if (cc.size() % j == 0) {
      REP(st, j) {
        bool f = true;
        for (int k = st; k < int(cc.size()); k += j) if (cc[st] != cc[k]) f = false;
        if (f) chkmin(ans, j);
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}