#include<bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int n, m;
long long a[maxn];
int visited[maxn];
long long weight[maxn];
vector<pair<int, int>> g[maxn];
vector<int> odd, even;
long long sumodd, sumeven;
int parEdge[maxn];
vector<int> oddcycle;
pair<int, int> edges[maxn];

void dfs_prepare(int v, int color) {
  if(!v) {
    fill(visited, visited + maxn, -1);
  }
  visited[v] = color;
  if(color) {
    sumodd += a[v];
    odd.emplace_back(v);
  }
  else {
    sumeven += a[v];
    even.emplace_back(v);
  }
  for(auto &e : g[v]) {
    if(visited[e.first] != -1) {
      if(visited[e.first] != visited[v] || oddcycle.size() > 0) continue;
      oddcycle.emplace_back(color);
      oddcycle.emplace_back(e.second);
      for(int x = v; x != e.first; x = x ^ edges[parEdge[x]].first ^ edges[parEdge[x]].second) {
        oddcycle.emplace_back(parEdge[x]);
      }
      continue;
    }
    int s = e.first;
    parEdge[s] = e.second;
    dfs_prepare(s, 1 - color);
  }
}

long long fs[maxn];

int same(int x, int y) {
  return x / abs(x) == y / abs(y);
}

void upd(int x, int w, int sign = 1) {
  if(a[x] < 0) {
    a[x] += w;
    fs[x] += sign * w;
  }
  else {
    a[x] -= w;
    fs[x] -= sign * w;
  }
}

void normalize(vector<int> ids) {
  vector<int> stac;
  for(int x : ids) {
    if(a[x] == 0) continue;
    if(stac.empty() || same(a[x], a[stac.back()])) {
      stac.push_back(x);
    }
    else {
      while(abs(a[x]) > 0) {
        if(stac.empty()) break;
        int y = stac.back();
        int w = min(abs(a[x]), abs(a[y]));
        upd(x, w); upd(y, w);
        if(a[y] == 0) stac.pop_back();
      }
      if(abs(a[x]) > 0) stac.push_back(x);
    }
  }
}

void dfs_solve(int v) {
  if(!v) {
    fill(visited, visited + maxn, -1);
  }
  visited[v] = 1;
  for(auto &e : g[v]) {
    int s = e.first, w = e.second;
    if(visited[s] != -1) continue;
    dfs_solve(s);
    weight[w] += fs[s];
    fs[v] -= fs[s];
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[--u].emplace_back(--v, i);
    g[v].emplace_back(u, i);

    weight[i]++;
    a[v]++;
    a[u]++;
    edges[i] = make_pair(u, v);
  }
  dfs_prepare(0, 0);

  if(sumodd != sumeven) {
    if(oddcycle.empty()) {
      cout << "NO" << endl;
      return 0;
    }
    long long need = sumodd - sumeven;
    need /= 2;

    int sign = 1;
    if(oddcycle.front() == 0) sign *= -1;

    for(int i = 1; i < oddcycle.size(); ++i) {
      auto [u, v] = edges[oddcycle[i]];
      a[v] -= sign * need;
      a[u] -= sign * need;
      weight[oddcycle[i]] -= sign * need;
      sign *= -1;
    }
  }

  normalize(even); normalize(odd);
  for(int i = 0, j = 0;;) {
    if(i == even.size() || j == odd.size()) break;
    if(a[even[i]] == 0) {
      ++i; continue;
    }
    if(a[odd[j]] == 0) {
      ++j; continue;
    }
    int x = even[i], y = odd[j];
    int w = min(abs(a[x]), abs(a[y]));
    upd(x, w);
    upd(y, w);
  }
  dfs_solve(0);

  cout << "YES\n";
  for(int i = 0; i < m; ++i) cout << -weight[i] << "\n";



  return 0;
}