#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n , m;
vector < int > v[N];
int a , b;
int tin[N];
int anc[N];
int scc[N];
int cnt;
int timer;
stack < int > s;
bool onstack[N];
int ans;
int mn[N];
void dfs(int node){
	tin[node] = anc[node] = ++timer;
	s.push(node);
	onstack[node] = 1;
	for(int next : v[node]){
		if(!tin[next]){
			dfs(next);
			anc[node] = min(anc[node] , anc[next]);
		}
		else if(onstack[next]){
			anc[node] = min(anc[node] , tin[next]);
		}
	}
	if(tin[node] == anc[node]){
		++cnt;
		++ans;
		int tmp;
		do{
			tmp = s.top();
			s.pop();
			onstack[tmp] = 0;
			scc[tmp] = cnt;
			++mn[cnt];
		}while(tmp != node);
		if(mn[cnt] == 1){
			mn[cnt] = -1;
		}
	}
}
int dist[N];
int bfs(int node){
	queue < int > q;
	for(int i = 1 ; i <= n ; ++i){
		dist[i] = n + 1;
	}
	dist[node] = 0;
	int ret = n + 1;
	q.push(node);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int next : v[node]){
			if(scc[next] == scc[node] && dist[next] > dist[node] + 1){
				dist[next] = dist[node] + 1;
				q.push(next);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(scc[i] == scc[node]){
			for(int next : v[i]){
				if(next == node){
					ret = min(ret , dist[i] + 1);
				}
				if(scc[next] != scc[node]){
					ret = -1;
				}
			}
		}
	}
	return ret;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
	}
	ans = n;
	for(int i = 1 ; i <= n ; ++i){
		if(!tin[i]){
			dfs(i);			
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		mn[scc[i]] = min(mn[scc[i]] , bfs(i));
	}
	for(int i = 1 ; i <= cnt ; ++i){
		ans += max(mn[i] * 998 , -1);
	}
	printf("%d\n" , ans);
}