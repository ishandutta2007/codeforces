#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

template <typename Weight, int MAX_N, Weight INF> class MaxFlow{
private:
	struct E{
		int to, rev;
		Weight lim;
		E(int x, Weight y, int z){
			to = x;
			lim = y;
			rev = z;
		}
	};

	vector<E> edge[MAX_N];
	int lev[MAX_N];
	int iter[MAX_N];


	Weight dfs(int s, int g, Weight f){
		if(s == g)return f;
		for(int &i = iter[s];i < edge[s].size();i++){
			E &e = edge[s][i];
				if(lev[e.to] <= lev[s] || e.lim <= 0)continue;
			Weight tmp = dfs(e.to, g, min(f, e.lim));
			if(tmp<1e-9)continue;
			e.lim -= tmp;
			edge[e.to][e.rev].lim += tmp;
			return tmp;
		}
		return 0;
	}

	void bfs(int x){
		queue<int> q;
		q.push(x);
		int p = 0;
			while(!q.empty()){
			for(int i = q.size();i--;){
				int tmp = q.front();q.pop();
				if(lev[tmp] != INF)continue;
				lev[tmp] = p;
				for(int j = 0;j < edge[tmp].size();j++){
					if(edge[tmp][j].lim > 0 && lev[edge[tmp][j].to] == INF)q.push(edge[tmp][j].to);
				}
			}
			p++;
		}
	}

public:
	void make_edge(int a, int b, Weight l){
		edge[a].push_back(E(b, l, edge[b].size()));
		edge[b].push_back(E(a, 0, edge[a].size() - 1));
	}

	Weight max_flow(int s, int g){
		Weight res = 0;
		bool fin = false;
		while(!fin){
			fill(lev, lev + MAX_N, INF);
			fill(iter, iter + MAX_N, 0);
			bfs(s);
			fin = true;
			while(true){
				Weight p = dfs(s, g, INF);
				if(p < 1e-9)break;
				fin = false;
				res += p;
			}
		}	
		return res;
	}
};

int v, e, n, k;
int dist[648][648];
int s[648];
int a, b, t;
bool ok(int x){
  MaxFlow<int, 1234, (1<<29)> mf;
  int S = v * 2, T = v * 2 + 1;
  for(int i = 0;i < n;i++){
	mf.make_edge(S, s[i], 1);
  }
  for(int i = 0;i < v;i++){
	mf.make_edge(v + i, T, 1);
  }
  for(int i = 0;i < v;i++){
	for(int j = 0;j < v;j++){
	  if(dist[i][j] <= x)mf.make_edge(i, v + j, 1<<29);
	}
  }
  return mf.max_flow(S, T) >= k;
}

int main(){
  cin >> v >> e >> n >> k;
  for(int i = 0;i < n;i++){
	cin >> s[i];s[i]--;
  }
  for(int i = 0;i < v;i++)
	for(int j = 0;j < v;j++)
	  dist[i][j] = (i==j)?0:1 << 29;
  for(int i = 0;i < e;i++){
	cin >> a >> b >> t;a--,b--;
	dist[a][b] = dist[b][a] = min(dist[a][b],t);
  }
  for(int i = 0;i < v;i++)
	for(int j = 0;j < v;j++)
	  for(int k = 0;k < v;k++)
		dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
  
  int bottom = 0, top = 1731312;
  if(!ok(top))top = -1;
  if(ok(0))top = 0;
  while(top - bottom > 1){
	int mid = (top + bottom) / 2;
	if(ok(mid))top = mid;
	else bottom = mid;
  }
  cout << top << endl;
  return 0;
}