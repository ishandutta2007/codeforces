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
int dp[maxn],
    up[maxn],
    used[maxn],
    a[maxn],
    n;
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
  dp[u] = a[u];
  for (int v : adj[u])
    if (v != p) {
      dfs(v, u);
      if (dp[v] >= 0) {
        dp[u] += dp[v];
        used[v] = true;
      }
    }
}

void sfd(int u, int p = -1) {
  if (p != -1)
    up[u] = max(0, up[p] + dp[p] - (used[u] ? dp[u] : 0));
  for (int v : adj[u])
    if (v != p)
      sfd(v, u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0)
      a[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    int fi, se;
    cin >> fi >> se;
    fi--, se--;
    adj[fi].PB(se);
    adj[se].PB(fi);
  }
  dfs(0);
  sfd(0);
  for (int i = 0; i < n; i++)
    cout << dp[i] + up[i] << ' ';
  cout << '\n';
	return 0;
}