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

int T, n, now;
int nxt[maxn], ans[maxn];
vector<int> G[maxn];

void dfs(int u) {
  ans[u] = now--;
  for (auto v : G[u]) dfs(v);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    FOR(i, 1, n + 1) G[i].clear();
    FOR(i, 1, n) {
      scanf("%d", nxt + i);
      if (nxt[i] == -1) nxt[i] = i + 1;
      G[nxt[i]].eb(i);
    }
    now = n + 1;
    dfs(n + 1);
    bool flag = true;
    vector<int> q;
    ROF(i, n, 1) {
      while (!q.empty() && ans[q.back()] < ans[i]) q.pop_back();
      if (q.empty() && nxt[i] != n + 1) {
        flag = false;
        break;
      }
      if (!q.empty() && q.back() != nxt[i]) {
        flag = false;
        break;
      }
      q.eb(i);
    }
    if (!flag) {
      puts("-1");
      continue;
    }
    FOR(i, 1, n) printf("%d ", ans[i]);
    puts("");
  }
}