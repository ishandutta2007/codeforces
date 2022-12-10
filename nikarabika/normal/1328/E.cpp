//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5 + 10;
int st[maxn],
    ft[maxn],
    par[maxn],
    n, q, tim;
vector<int> adj[maxn];

bool cmp(int u, int v) {
  return st[u] < st[v];
}

void dfs(int u, int p = -1) {
  st[u] = tim++;
  par[u] = p;
  for (auto v : adj[u])
    if (v != p)
      dfs(v, u);
  ft[u] = tim;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int fi, se;
    cin >> fi >> se;
    fi--, se--;
    adj[fi].PB(se);
    adj[se].PB(fi);
  }
  dfs(0);
  while (q--) {
    int qc;
    cin >> qc;
    vector<int> vrts;
    while (qc--) {
      int v;
      cin >> v;
      if (v != 1)
        vrts.PB(par[v - 1]);
    }
    sort(all(vrts), cmp);
    bool bad = false;
    for (int i = 0; i + 1 < sz(vrts); i++) {
      int u = vrts[i],
          v = vrts[i + 1];
      if (st[u] <= st[v] and st[v] < ft[u]);
      else {
        bad = true;
        break;
      }
    }
    if (bad)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
	return 0;
}