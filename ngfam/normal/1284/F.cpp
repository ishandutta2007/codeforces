#include <bits/stdc++.h>

using namespace std;

const int N = 250005;

int n;
int height[N];
int jump[N][20];

int id[N];
int par[N];
set < int > ga[N], gb[N];
vector < int > comp[N];

void dfs_prepare(int v, int p) {
  for(int s : ga[v]) if(s != p) {
    par[s] = v;
    height[s] = height[v] + 1;
    jump[s][0] = v;
    for(int i = 1; i < 20; ++i) {
      jump[s][i] = jump[jump[s][i - 1]][i - 1];
    }
    dfs_prepare(s, v);
  }
}

int lca(int x, int y) {
  if(height[y] > height[x]) swap(x, y);
  for(int i = 19; i >= 0; --i) if(height[jump[x][i]] >= height[y]) x = jump[x][i];
  if(x == y) return x;
  for(int i = 19; i >= 0; --i) if(jump[x][i] != jump[y][i]) {
    x = jump[x][i];
    y = jump[y][i];
  }
  return jump[x][0];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;

  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    ga[u].insert(v);
    ga[v].insert(u);
  }

  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    gb[u].insert(v);
    gb[v].insert(u);
  }

  dfs_prepare(0, -1);

  for(int i = 0; i < n; ++i) {
    id[i] = i;
    comp[i].push_back(i);
  }

  vector < int > leaves;
  for(int i = 0; i < n; ++i) {
    if(gb[i].size() == 1) leaves.push_back(i);
  }

  map < pair < int, int >, pair < int, int > > answer;

  for(int i = 1; i < n; ++i) {
    int x = leaves.back(); leaves.pop_back();
    int y = *gb[x].begin();

    int p = lca(x, y), u, v;
    pair < int, int > ret;
    if(id[p] != id[x]) {
      int temp = x;
      for(int j = 19; j >= 0; --j) {
        if(height[jump[temp][j]] < height[p]) continue;
        if(id[jump[temp][j]] == id[x]) {
          temp = jump[temp][j];
        }
      }
      u = temp; v = par[temp];
      ret = make_pair(id[temp], id[par[temp]]);
    }
    else {
      int temp = y;
      for(int j = 19; j >= 0; --j) {
        if(height[jump[temp][j]] < height[p]) continue;
        if(id[jump[temp][j]] != id[p]) {
          temp = jump[temp][j];
        }
      }
      u = temp; v = par[temp];
      ret = make_pair(id[temp], id[par[temp]]);
    }

    if(comp[ret.first].size() < comp[ret.second].size()) swap(ret.first, ret.second);
    for(int v : comp[ret.second]) {
      id[v] = ret.first;
      comp[ret.first].push_back(v);
    }

    answer[{u, v}] = {x, y};

    gb[x].erase(y);
    gb[y].erase(x);
    if(gb[y].size() == 1) leaves.push_back(y);
  }

  cout << n - 1 << "\n";
  for(auto p : answer) {
    auto x = p.first, y = p.second;
    cout << x.first + 1 << " " << x.second + 1 << " " << y.first + 1 << " " << y.second + 1 << "\n";
  }

  return 0;
}