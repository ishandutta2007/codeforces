#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 300030;

int n, q;
int starting_cost;

vector<int> chain;
vector<pair<int, int>> g[MAXN];

bool inChain[MAXN];

int cost_prev[MAXN];
int cost_next[MAXN];

bool dfs_findchain(int v, int p) {
  if(v == n - 1) {
    chain.push_back(v);
    return inChain[v] = true;
  }

  for(auto &e : g[v]) {
    int s = e.first, w = e.second;
    if(s == p) continue;
    if(dfs_findchain(s, v)) {
      cost_next[v] = w;
      cost_prev[s] = w;
      starting_cost += w;
      inChain[v] = true;
    }
  }
  if(inChain[v]) chain.push_back(v);
  return inChain[v];
}

vector<pair<int, int>> sub[MAXN];

void dfs_chain(int v, int p, int cst, int root) {
  sub[root].emplace_back(v, cst);
  for(auto &e : g[v]) {
    int s = e.first, w = e.second;
    if(s == p || inChain[s]) continue;
    dfs_chain(s, v, cst + w, root);
  }
}

main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> q;
  for(int i = 0; i + 1 < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[--u].emplace_back(--v, w);
    g[v].emplace_back(u, w);
  }

  dfs_findchain(0, -1);
  reverse(chain.begin(), chain.end());

  for(int v : chain) dfs_chain(v, -1, 0, v);

  int ans_cost = 0, best_cost = -1e18;

  int cur_cost = starting_cost;

  for(int i = 0; i < chain.size(); ++i) {
    int v = chain[i];
    if(sub[v].size() > 2) {
      ans_cost = 1e18;
      break;
    }

    for(auto &a : sub[v]) {

      ans_cost = max(ans_cost, best_cost + cur_cost + a.second);
    }
    if(sub[v].size() > 1) {
      best_cost = max(best_cost, starting_cost - cur_cost + sub[v].back().second);
      if(i > 0) ans_cost = max(ans_cost, starting_cost - cost_prev[v] + sub[v].back().second);
    }
    if(i > 0) best_cost = max(best_cost, starting_cost - (cur_cost + cost_prev[v]));
    cur_cost -= cost_next[v];
  }

  while(q--) {
    int x; cin >> x;
    cout << min(starting_cost, ans_cost + x) << "\n";
  }

  return 0;
}