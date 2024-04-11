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
const int maxa = 1123456;

int n, a[maxn], vis[maxa];
vector<pii> G[maxa];

int bfs(int s) {
  vector<int> f(1e6 + 5, n + 5);
  vector<char> checked(n + 1);
  f[s] = 0;
  queue<int> q;
  q.emplace(s);
  int ret = n + 5;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto [id, v] : G[u]) if (!checked[id]) {
      if (f[v] > n) {
        f[v] = f[u] + 1;
        q.emplace(v);
      } else chkmin(ret, f[u] + f[v] + 1);
      checked[id] = true;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  vis[1] = 1;
  FOR(i, 2, 1e6) if (!vis[i]) {
    vis[i] = i;
    for (ll j = ll(i) * i; j <= 1e6; j += i) vis[j] = i;
  }
  FOR(i, 1, n) {
    map<int, int> cnt;
    while (a[i] != 1) {
      cnt[vis[a[i]]]++;
      a[i] /= vis[a[i]];
    }
    vector<int> now;
    for (auto [x, y] : cnt) if (y % 2 == 1) now.eb(x);
    if (now.empty()) {
      puts("1");
      return 0;
    }
    if (now.size() == 1) now.eb(1);
    G[now[0]].eb(i, now[1]); G[now[1]].eb(i, now[0]);
  }
  int ans = n + 5;
  FOR(i, 1, 1000) if (vis[i] == i) chkmin(ans, bfs(i));
  if (ans > n) ans = -1;
  printf("%d", ans);
}