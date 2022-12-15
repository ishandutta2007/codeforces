#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1000 * 1000;

vector<int> valeurs;
vector<int> adj[MAXN];
vector<int> used;
vector<bool> seen;

bool dfs(int u) {
  if (seen[u])
    return false;
  seen[u] = true;
  for (int v : adj[u])
    if (used[v] == -1 or dfs(used[v])) {
      used[v] = u;
      return true;
    }
  return false;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  for (int x : a)
    for (int i = 1; i <= n; ++i)
      valeurs.push_back(i * x);
  sort(valeurs.begin(), valeurs.end());
  valeurs.resize(unique(valeurs.begin(), valeurs.end()) - valeurs.begin());
  int m = valeurs.size();
  used.assign(n, -1);
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= n; ++j) {
      int x = a[i] * j;
      int pos =
          lower_bound(valeurs.begin(), valeurs.end(), x) - valeurs.begin();
      adj[pos].push_back(i);
    }

  int sol = 0;
  seen.assign(m, false);
  for (int i = 0; i < m; ++i)
    if (dfs(i)) {
      sol += valeurs[i];
      seen.assign(m, false);
    }
  cout << sol << endl;
}