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

vector<int> G[maxn];
int ans[maxn], n, u[maxn], v[maxn], pre[maxn];
bool vis[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n - 1) {
    scanf("%d%d", u + i, v + i);
    G[u[i]].eb(i); G[v[i]].eb(i);
  }
  if (n == 2) {
    puts("0");
    return 0;
  }
  vector<int> en;
  FOR(i, 1, n) if (G[i].size() == 1) {
    en.eb(i);
    if (en.size() == 2) break;
  }
  reset(ans, -1);
  queue<int> q;
  q.emplace(en[0]);
  while (!q.empty()) {
    auto x = q.front(); q.pop();
    vis[x] = true;
    for (auto e : G[x]) {
      int y = u[e] ^ v[e] ^ x;
      if (!vis[y]) {
        pre[y] = e;
        if (y == en[1]) break;
        q.emplace(y);
      }
    }
  }
  int now = n - 2, last = -1;
  bool fi = true;
  for (int x = en[1]; x != en[0]; x = u[pre[x]] ^ v[pre[x]] ^ x) {
    if (fi) {
      fi = false;
      ans[pre[x]] = 1;
    } else {
      ans[pre[x]] = now--;
      last = pre[x];
    }
  }
  ans[last] = 0;
  now++;
  FOR(i, 1, n - 1) if (ans[i] == -1) ans[i] = now--;
  FOR(i, 1, n - 1) printf("%d\n", ans[i]);
}