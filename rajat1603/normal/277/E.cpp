#include "bits/stdc++.h"
using namespace std;
namespace mcmf{
	const int V = 805;
	const int E = 2e6 + 6;
	const int inf = 1e9 + 9;
	const double eps = 1e-9;
	int from[E];
	int to[E];
	int cap[E];
	double cst[E];
	int cur;
	vector < int > v[V];
	int s , t;
	void init(){
		for(int i = 0 ; i < V ; ++i){
			v[i].clear();
		}
		cur = 0;
	}
	void addedge(int a , int b , int c , double d){
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
	double dist[V];
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
				if(dist[next] > dist[node] + cst[edge] + eps){
					dist[next] = dist[node] + cst[edge];
					que[qr++] = next;
					prv[next] = edge;
				}
			}
		}
		return dist[t] < inf - eps;
	}
	double flow(int &tot){
		double res = 0;
		tot = 0;
		while(bfs()){
			++tot;
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
const int N = 405;
int n;
pair < int , int > arr[N];
double dist(int i , int j){
	int dx = arr[i].first - arr[j].first;
	int dy = arr[i].second - arr[j].second;
	return sqrt(1LL * dx * dx + 1LL * dy * dy);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &arr[i].second , &arr[i].first);
	}
	sort(arr + 1 , arr + 1 + n);
	mcmf :: init();
	mcmf :: s = 0;
	mcmf :: t = n + n + 1;
	for(int i = 1 ; i <= n ; ++i){
		mcmf :: addedge(mcmf :: s , i + n , 1 , 0);
		mcmf :: addedge(i , mcmf :: t , 2 , 0);
		for(int j = i + 1 ; j <= n ; ++j){
			if(arr[j].first > arr[i].first){
				mcmf :: addedge(i + n , j , 1 , dist(i , j));
			}
		}
	}
	int flow = 0;
	double ans = mcmf :: flow(flow);
	if(flow != n - 1){
		printf("-1\n");
		return 0;
	}
	printf("%.9lf\n" , ans);
}