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

const int maxn = 2e5 + 20;
unsigned int mark[maxn];
int n, m, a, b;
vector<int> adj[maxn];

int dfs(int u, int bad) {
  if (mark[u]++)
    return 0;
  int size = 1;
  for (int v : adj[u])
    if (v != bad)
      size += dfs(v, bad);
  return size;
}

int solve() {
  cin >> n >> m >> a >> b;
  a--, b--;
  for (int i = 0; i < n; i++)
    adj[i].clear();
  for (int i = 0; i < m; i++) {
    int fi, se;
    cin >> fi >> se;
    fi--, se--;
    adj[fi].PB(se);
    adj[se].PB(fi);
  }
  fill(mark, mark + n, 0);
  LL x = dfs(a, b);
  fill(mark, mark + n, 0);
  LL y = dfs(b, a);
  cout << (n - x - 1) * (n - y - 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}