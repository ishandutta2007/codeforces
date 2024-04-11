#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
const int inf = 1e9 + 9;
int n , m;
int ans[N];
int a[N] , b[N] , c[N];
int perm[N];
int parent[N];
int inmst[N];
vector < int > v[N];
int dp[LN][N];
int mx[LN][N];
int mn[LN][N];
int depth[N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void stuff(int edge){
	if(find(a[edge]) != find(b[edge])){
		inmst[edge] = 1;
		parent[find(a[edge])] = find(b[edge]);
		v[a[edge]].emplace_back(edge);
		v[b[edge]].emplace_back(edge);
	}
	else{
		inmst[edge] = 0;
	}
}
void dfs(int node , int parent){
	dp[0][node] = parent;
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent){
			mx[0][next] = c[edge];
			depth[next] = depth[node] + 1;
			dfs(next , node);
		}
	}
}
pair < int , int > get(int a , int b){
	int dif = depth[a] - depth[b];
	if(dif < 0){
		swap(a , b);
		dif *= -1;
	}
	int res = 0;
	for(int i = 0 ; i < LN ; ++i){
		if(dif & (1 << i)){
			res = max(res , mx[i][a]);
			a = dp[i][a];
		}
	}
	if(a != b){
		for(int i = LN - 1 ; i >= 0 ; --i){
			if(dp[i][a] != dp[i][b]){
				res = max(res , mx[i][a]);
				res = max(res , mx[i][b]);
				a = dp[i][a];
				b = dp[i][b];
			}
		}
		res = max(res , mx[0][a]);
		res = max(res , mx[0][b]);
		a = dp[0][a];
		b = dp[0][b];
	}
	return make_pair(a , res);
}
void update(int node , int ancestor , int val){
	int dif = depth[node] - depth[ancestor];
	for(int i = LN - 1 ; i >= 0 ; --i){
		if(dif & (1 << i)){
			mn[i][node] = min(mn[i][node] , val);
			node = dp[i][node];
		}
	}
}
void dfs2(int node , int parent){
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(next != parent){
			ans[edge] = mn[0][next];
			dfs2(next , node);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		perm[i] = i;
	}
	sort(perm + 1 , perm + 1 + m , [](int x , int y){
		return make_pair(c[x] , make_pair(a[x] , b[x])) < make_pair(c[y] , make_pair(a[y] , b[y]));
	});
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	for(int i = 1 ; i <= m ; ++i){
		stuff(perm[i]);
	}
	depth[1] = 0;
	dfs(1 , 0);
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
			mx[i][j] = max(mx[i - 1][j] , mx[i - 1][dp[i - 1][j]]);
		}
	}
	for(int i = 0 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			mn[i][j] = inf;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		if(inmst[i]){
			ans[i] = inf;
		}
		else{
			auto it = get(a[i] , b[i]);
			ans[i] = it.second;
			update(a[i] , it.first , c[i]);
			update(b[i] , it.first , c[i]);
		}
	}
	for(int i = LN - 1 ; i > 0 ; --i){
		for(int j = 1 ; j <= n ; ++j){
			mn[i - 1][j] = min(mn[i][j] , mn[i - 1][j]);
			mn[i - 1][dp[i - 1][j]] = min(mn[i - 1][dp[i - 1][j]] , mn[i][j]);
		}
	}
	dfs2(1 , 0);
	for(int i = 1 ; i <= m ; ++i){
		if(ans[i] == inf){
			ans[i] = 0;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		printf("%d%c" , ans[i] - 1 , " \n"[i == m]);
	}
}