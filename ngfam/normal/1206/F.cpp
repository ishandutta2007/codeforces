#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int d[N];
int child[N];
vector < int > g[N];

void pre_dfs(int v, int p) {
  child[v] = 1;
  for(int s : g[v]) {
    if(s == p) continue;
    pre_dfs(s, v);
    child[v] += child[s];
  }
}

int find_centroid(int v, int p) {
  for(int s : g[v]) if(s != p) {
    if(child[s] * 2 >= n) return find_centroid(s, v);
  }
  return v;
}

void go(int v, int p, int &cur, int delta) {
  cur += delta;
  d[v] = cur;
  cout << v << " " << p << " " << d[v] - d[p] << endl;
  for(int s : g[v]) if(s != p) {
    go(s, v, cur, delta);
  }
}

bitset < 1010 > dp[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  srand(time(NULL));

  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  pre_dfs(1, 0);
  int root = find_centroid(1, 0);
  pre_dfs(root, 0);

  int sum_a = 0, sum_b = 0;
  vector < int > a, b;

  dp[0][0] = 1;
  for(int i = 0; i < g[root].size(); ++i) {
    dp[i + 1] = (dp[i] | (dp[i] << child[g[root][i]]));
  }

  int best = n / 2;
  while(!dp[g[root].size()][best]) --best;

  for(int i = g[root].size() - 1; i >= 0; --i) {
    int x = g[root][i];
    if(dp[i][best]) {
      a.push_back(x);
      sum_a += child[x];
    }
    else {
      b.push_back(x);
      sum_b += child[x];
      best -= child[x];
    }
  }

  int cur_a = 0, cur_b = 0;
  for(int node : a) {
    go(node, root, cur_a, 1);
  }

  for(int node : b) {
    go(node, root, cur_b, sum_a + 1);
  }

  return 0;
}