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

int m;
bool vis[maxn], ans[maxn];
vector<int> n, G[maxn];

void dfs(int u, bool c) {
  ans[u] = c;
  vis[u] = true;
  if (!vis[G[u][0]]) dfs(G[u][0], !c);
  else if (!vis[G[u][1]]) dfs(G[u][1], !c);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> m;
  n.resize(m + 1);
  int tot = 0;
  map<int, int> last;
  FOR(i, 1, m) {
    cin >> n[i];
    FOR(j, 1, n[i]) {
      tot++;
      int a; cin >> a;
      if (tot % 2 == 0) {
        G[tot].eb(tot - 1);
        G[tot - 1].eb(tot);
      }
      if (last[a]) {
        G[tot].eb(last[a]);
        G[last[a]].eb(tot);
        last.erase(a);
      } else last[a] = tot;
    }
  }
  if (!last.empty()) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  FOR(i, 1, tot) if (!vis[i]) dfs(i, false);
  tot = 0;
  FOR(i, 1, m) {
    FOR(j, 1, n[i]) {
      tot++;
      cout << (ans[tot] ? 'L' : 'R');
    }
    cout << '\n';
  }
}