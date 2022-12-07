#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n;
vector < int > g[N];

int id[N];
int ntime;
int inv[N];
int par[N];
vector < int > answer;

int f[N];

void precalc(int v) {
  f[v] = 1;
  for(int s : g[v]) precalc(s), f[v] = max(f[v], f[s] + 1);
}

void move(int u, int v) { /// move v to become the children of u
  if(id[v] < id[u]) assert(0);
  while(par[v] != u) {
    if(par[v] == 0) assert(0);
    answer.push_back(v);
    par[v] = par[par[v]];
  }
}

void pre_dfs(int v) {
  id[v] = ++ntime;
  inv[ntime] = v;
  sort(g[v].begin(), g[v].end(), [&](int x, int y){
    return f[x] < f[y];
  });
  for(int s : g[v]) {
    pre_dfs(s);
  }
}

void solve(int v) {
  if(g[v].size() == 0) return;
  for(int s : g[v]) solve(s);
  for(int i = g[v].size() - 1; i > 0; --i) {
    move(g[v][i - 1], g[v][i]);
  }
  for(int i = 1; i < g[v].size(); ++i) {
    move(v, g[v][i]);
  }
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  srand(time(NULL));
  cin >> n;

  for(int i = 1; i < n; ++i) {
    int v; cin >> v;
    g[v + 1].push_back(i + 1);
  }

  precalc(1);
  pre_dfs(1);
  for(int i = 1; i <= n; ++i) {
    cout << inv[i] - 1 << " ";
    par[inv[i]] = inv[i - 1];
  }
  cout << endl;

  solve(1);

  cout << answer.size() << endl;
  for(int x : answer) cout << x - 1 << " ";

  return 0;
}