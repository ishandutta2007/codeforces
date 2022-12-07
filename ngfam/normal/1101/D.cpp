#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n;
int a[N];
vector < int > g[N];
vector < int > vec[N];

int cnt;
int mark[N + N];
int head[N + N];
int link[N + N];
int vertice[N + N];

void addEdge(int u, int v) {
  vertice[++cnt] = v;
  link[cnt] = head[u];
  head[u] = cnt;
}

pair < int, int > dfs(int v, int p = -1) {
  mark[v] = 1;
  pair < int, int > ans = make_pair(1, v);
  for(int id = head[v]; id > 0; id = link[id]) {
    int u = vertice[id];
    if(u == p) continue;
    pair < int, int > get = dfs(u, v);
    ans = max(ans, make_pair(get.first + 1, get.second));
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
	
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], vec[a[i]].push_back(i);

  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int res = 0;

  for(int i = 2; i < N; ++i) {
    for(int j = i; j < N; j += i) {
      for(int v : vec[j]) {
        for(int u : g[v]) if(a[u] % i == 0) addEdge(u, v);
      }
    }

    for(int j = i; j < N; j += i) {
      for(int v : vec[j]) {
        if(mark[v]) continue;
        pair < int, int > w = dfs(v);
        res = max(res, dfs(w.second, -1).first);
      }
    }

    cnt = 0;
    for(int j = i; j < N; j += i) {
      for(int v : vec[j]) {
        head[v] = mark[v] = 0;
      }
    }
  }

  cout << res;

  return 0;
}