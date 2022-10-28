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
const int N = 105;
int n;
char str[N];
int b[N];
int cnt[30];
int main(){
	scanf("%d" , &n);
	scanf("%s" , str + 1);
	for(int i = 1 ; i <= n ; ++i){
		++cnt[str[i] - 'a' + 1];
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	mcmf :: init();
	mcmf :: s = 0;
	mcmf :: t = (n / 2) + 27;
	for(int i = 1 ; i <= (n / 2) ; ++i){
		mcmf :: addedge(mcmf :: s , i , 2 , 0);
	}
	for(int i = (n / 2) + 1 ; i <= (n / 2) + 26 ; ++i){
		mcmf :: addedge(i , mcmf :: t , cnt[i - (n / 2)] , 0);
	}
	for(int i = 1 ; i <= (n / 2) ; ++i){
		for(int j = 0 ; j < 26 ; ++j){
			int cst = 0;
			if(str[i] - 'a' == j){
				cst = min(cst , -b[i]);
			}
			if(str[n - i + 1] - 'a' == j){
				cst = min(cst , -b[n - i + 1]);
			}
			mcmf :: addedge(i , (n / 2) + 1 + j , 1 , cst);
		}
	}
	printf("%d\n" , -mcmf :: flow());
}