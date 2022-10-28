#include "bits/stdc++.h"
using namespace std;
namespace mcmf{
	const int V = 105;
	const int E = 2e4 + 4;
	const int inf = 1e6 + 6;
	int from[E];
	int to[E];
	int cap[E];
	int cst[E];
	int cur;
	vector < int > v[V];
	int s , t;
	void init(){
		for(int i = 0 ; i < V ; ++i){
			v[i].clear();
		}
		cur = 0;
	}
	void addedge(int a , int b , int c , int d){
		from[cur] = a;
		to[cur] = b;
		cap[cur] = c;
		cst[cur] = d;
		v[a].emplace_back(cur);
		++cur;
		from[cur] = b;
		to[cur] = a;
		cap[cur] = 0;
		cst[cur] = -d;
		v[b].emplace_back(cur);
		++cur;
	}
	int que[E + V];
	int ql;
	int qr;
	int dist[V];
	int prv[V];
	bool bfs(){
		for(int i = 0 ; i < V ; ++i){
			dist[i] = inf;
		}
		ql = qr = 0;
		que[qr++] = s;
		dist[s] = 0;
		while(ql < qr){
			int node = que[ql++];
			for(int edge : v[node]){
				if(cap[edge] == 0){
					continue;
				}
				int next = to[edge];
				if(dist[next] > dist[node] + cst[edge]){
					dist[next] = dist[node] + cst[edge];
					que[qr++] = next;
					prv[next] = edge;
				}
			}
		}
		return dist[t] < inf;
	}
	int flow(){
		int res = 0;
		while(bfs()){
			int node = t;
			while(node != s){
				int edge = prv[node];
				--cap[edge];
				++cap[edge ^ 1];
				node = from[edge];
			}
			res += dist[t];
		}
		return res;
	}
};
const int N = 55;
int n , q;
int type , l , r , val;
int ql[N];
int qr[N];
int main(){
	scanf("%d %d" , &n , &q);
	for(int i = 1 ; i <= n ; ++i){
		ql[i] = 1;
		qr[i] = n;
	}
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d %d %d" , &type , &l , &r , &val);
		for(int j = l ; j <= r ; ++j){
			if(type == 1){
				ql[j] = max(ql[j] , val);
			}
			else{
				qr[j] = min(qr[j] , val);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(ql[i] > qr[i]){
			printf("-1\n");
			return 0;
		}
	}
	mcmf :: init();
	for(int i = 1 ; i <= n ; ++i){
		mcmf :: addedge(0 , i , 1 , 0);
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = ql[i] ; j <= qr[i] ; ++j){
			mcmf :: addedge(i , j + n , 1 , 0);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			mcmf :: addedge(i + n , n + n + 1 , 1 , j * 2 - 1);
		}
	}
	mcmf :: s = 0;
	mcmf :: t = n + n + 1;
	printf("%d\n" , mcmf :: flow());
}