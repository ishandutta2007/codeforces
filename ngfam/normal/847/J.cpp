#include <bits/stdc++.h>

using namespace std;

const int N = 20020;

struct dinic{
  struct TEdge{
    int v;
    int f;
    int c;
    int rev;
    TEdge(int x, int y, int z){
      v = x;
      f = 0;
      c = y;
      rev = z;
    }
  };

  int start[N];
  int level[N];
  vector < int > g[N];
  vector < TEdge > edges;

  void addEdge(int u, int v, int c){
 //   cout << u << " " << v << endl;
    edges.emplace_back(v, c, edges.size() + 1);
    edges.emplace_back(u, 0, edges.size() - 1);
    g[u].push_back(edges.size() - 2);
    g[v].push_back(edges.size() - 1);
  }

	void clr() {
		for(int i = 0; i < N; ++i) g[i].clear();
		edges.clear();
	}

  bool bfs(int S, int T){
    queue < int > que;
    que.push(S);

    fill(level, level + N, -1);
    level[S] = 0;

    while(que.size()){
      int x = que.front();
      que.pop();

      for(int id : g[x]){
        TEdge e = edges[id];
        if(e.f == e.c || level[e.v] != -1) continue;
        level[e.v] = level[x] + 1;
        que.push(e.v);
      }
    }

    if(level[T] == -1) return false;
    return true;
  }

  int dfs(int u, int flow, int T){
    if(u == T) return flow;
    for(; start[u] < g[u].size(); start[u]++){
      TEdge &e = edges[g[u][start[u]]];
      if(level[e.v] != level[u] + 1 || e.f == e.c) continue;
      int p = dfs(e.v, min(flow, e.c - e.f), T);
      if(p) {
        e.f += p;
        edges[e.rev].f -= p;
        return p;
      }
    }
    return 0;
  }

  int maxFlow(int S, int T){
    int ans = 0;
    while(bfs(S, T)){
      int x;
      memset(start, 0, sizeof start);
      while(x = dfs(S, 999999, T)){
        ans += x;
      }
    }
    return ans;
  }
}dinic;

int n, m;
pair < int, int > e[N];

bool f(int x) {
	dinic.clr();
	int source = 0, sink = n + m + 1;

	for(int i = 1; i <= n; ++i) {
		dinic.addEdge(source, i, x);
	}

	for(int i = 1; i <= m; ++i) {
		dinic.addEdge(e[i].first, i + n, 1);
		dinic.addEdge(e[i].second, i + n, 1);
		dinic.addEdge(i + n, sink, 1);
	}

	if(dinic.maxFlow(source, sink) == m) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> e[i].first >> e[i].second;
	}

	int lo = 0, hi = m, ans = m;
	while(lo <= hi) {
		int mid = (lo + hi) >> 1;
		if(f(mid)) {
			hi = mid - 1;
			ans = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << endl;
	f(ans);

	for(int i = 1; i <= n; ++i) {
		for(int id : dinic.g[i]) {
			auto &w = dinic.edges[id];
			if(w.f > 0) {
				int v = i ^ e[w.v - n].first ^ e[w.v - n].second;
				cout << i << " " << v << endl;
			}
		}
	}

  return 0;
}