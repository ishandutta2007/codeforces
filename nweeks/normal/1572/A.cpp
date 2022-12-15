#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<int> order;
vector<bool> seen;

void dfs(int u) {
  seen[u] = true;
  for (int v : adj[u])
    if (!seen[v])
      dfs(v);
  order.push_back(u);
}

void solve() {
  int nbChapitres;
  cin >> nbChapitres;
  adj.clear();
  adj.resize(nbChapitres);
  order.clear();
  seen.assign(nbChapitres, false);

  for (int i = 0; i < nbChapitres; ++i) {
    int nbAvant;
    cin >> nbAvant;
    for (int j = 0; j < nbAvant; ++j) {
      int v;
      cin >> v;
      --v;
      adj[v].push_back(i);
    }
  }
  for (int u = 0; u < nbChapitres; ++u)
    if (!seen[u]) {
      dfs(u);
    }
  reverse(order.begin(), order.end());
  vector<int> id(nbChapitres);
  for (int i = 0; i < nbChapitres; ++i)
    id[order[i]] = i;
  for (int u = 0; u < nbChapitres; ++u)
    for (int v : adj[u])
      if (id[v] < id[u]) {
        cout << -1 << '\n';
        return;
      }

  vector<int> timesBefore(nbChapitres, 0);

  int ret = 0;
  timesBefore[order[0]] = 1;
  for (int i = 0; i < nbChapitres; ++i) {
    int u = order[i];
    timesBefore[u] = max(timesBefore[u], 1LL);
    for (int v : adj[u]) {
      if (u < v)
        timesBefore[v] = max(timesBefore[u], timesBefore[v]);
      else
        timesBefore[v] = max(timesBefore[u] + 1, timesBefore[v]);
    }
    ret = max(ret, timesBefore[u]);
  }
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}