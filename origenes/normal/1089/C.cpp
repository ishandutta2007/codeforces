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

const int maxn = 512;

int dis[maxn][maxn];
int n, m;
vector<int> G[maxn];

void solve() {
  vector<int> good(n);
  iota(all(good), 1);
  string cmd;
  do {
    int best = 0, mn = n;
    FOR(i, 1, n) {
      int now = 0;
      for (auto j : G[i]) {
        int cur = 0;
        for (auto w : good) if (dis[j][w] < dis[i][w]) cur++;
        chkmax(now, cur);
      }
      if (mn > now) {
        mn = now;
        best = i;
      }
    }
    cout << best << endl;
    cin >> cmd;
    if (cmd == "GO") {
      int u; cin >> u;
      vector<int> nxt;
      for (auto v : good) if (dis[best][v] > dis[u][v]) nxt.eb(v);
      swap(good, nxt);
    }
  } while (cmd != "FOUND");
}

int main() {
  cin >> n >> m;
  while (m--) {
    int k, u, v;
    cin >> k >> u;
    REP(i, k - 1) {
      cin >> v;
      G[u].eb(v);
      G[v].eb(u);
      u = v;
    }
  }
  reset(dis, 0x3f);
  FOR(i, 1, n) {
    for (auto j : G[i]) dis[i][j] = 1;
    dis[i][i] = 0;
  }
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  REP(i, n) solve();
}