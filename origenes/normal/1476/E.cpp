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

int n, m, k;
int mt[maxn], deg[maxn];
string p[maxn], s[maxn];
vector<int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> k;
  FOR(i, 1, n) cin >> p[i];
  map<string, int> occ;
  FOR(i, 1, m) {
    cin >> s[i] >> mt[i];
    REP(j, k) if (p[mt[i]][j] != '_' && p[mt[i]][j] != s[i][j]) {
      cout << "NO";
      return 0;
    }
    if (!occ.count(p[mt[i]])) occ[p[mt[i]]] = mt[i];
    else if (occ[p[mt[i]]] != mt[i]) {
      cout << "NO";
      return 0;
    }
  }
  FOR(i, 1, n) if (!occ.count(p[i])) occ[p[i]] = i;
  FOR(i, 1, m) REP(mask, 1 << k) {
    string pattern = s[i];
    REP(j, k) if (mask & (1 << j)) pattern[j] = '_';
    if (pattern != p[mt[i]] && occ.count(pattern)) {
      int v = occ[pattern];
      G[mt[i]].eb(v);
      deg[v]++;
    }
  }
  queue<int> q;
  vector<int> ans;
  FOR(i, 1, n) if (!deg[i]) q.emplace(i);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    ans.eb(u);
    for (auto v : G[u]) if (!--deg[v]) q.emplace(v);
  }
  if (ans.size() == n) {
    cout << "YES\n";
    for (auto u : ans) cout << u << ' ';
  } else cout << "NO";
}