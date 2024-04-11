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

const int maxn = 612345;

int n;
bool in[maxn], out[maxn];
vector<int> G[maxn], s, way[2];
string pos[4];

void dfs(int u, int par) {
  s.eb(u);
  if (in[u]) return;
  in[u] = true;
  for (auto v : G[u]) if (v != par) {
    if (!in[v] || out[v] || u == v) {
      dfs(v, u);
      s.eb(u);
    }
  }
  out[u] = true;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    if (v != u) G[v].eb(u);
  }
  FOR(i, 1, 2 * n) if (!in[i]) {
    s.clear();
    dfs(i, 0);
    s.pop_back();
    if (size(s) == 2) {
      cout << "-1\n";
      return 0;
    }
    if (s.empty()) continue;
    int sum = size(s), cap = sum / 2;
    while (cap--) {
      way[1].eb(s.back());
      s.pop_back();
    }
    for (auto x : s) way[0].eb(x);
    sum /= 2;
    pos[0] += 'U', pos[1] += 'D';
    if (sum % 2 == 1) {
      REP(j, (sum - 1) / 2) REP(k, 4) pos[k] += "LR";
      pos[2] += 'U', pos[3] += 'D';
    } else {
      REP(j, (sum - 2) / 2) REP(k, 4) pos[k] += "LR";
      pos[2] += "LR", pos[3] += "LR";
      pos[0] += 'U', pos[1] += 'D';
    }
  }
  cout << "2 " << n << "\n\n";
  REP(i, 2) {
    for (auto x: way[i]) cout << x << ' ';
    cout << '\n';
  }
  cout << '\n';
  cout << pos[0] << '\n' << pos[1] << "\n\n" << pos[2] << '\n' << pos[3];
}