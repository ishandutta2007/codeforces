#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int LN = 19;
int n , m;
int a[N] , b[N];
vector < int > g[N];
int parent[N];
vector < int > v[N];
vector < pair < int , int > > cycle;
int dp[LN][N];
int depth[N];
int val[LN][N];
//int res[LN][N];
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
void dfs(int node , int parent){
	dp[0][node] = parent;
	for(int next : v[node]){
		if(next != parent){
			depth[next] = depth[node] + 1;
			dfs(next , node);
		}
	}
}
int get(int a , int b){
	int dif = depth[a] - depth[b];
	if(dif < 0){
		swap(a , b);
		dif = -dif;
	}
	int res = 0;
	for(int i = 0 ; i < LN ; ++i){
		if((dif >> i) & 1){
			res = max(res , val[i][a]);
			a = dp[i][a];
		}
	}
	if(a != b){
		for(int i = LN - 1 ; i >= 0 ; --i){
			if(dp[i][a] != dp[i][b]){
				res = max(res , val[i][a]);
				res = max(res , val[i][b]);
				a = dp[i][a];
				b = dp[i][b];
			}
		}
		res = max(res , a);
		res = max(res , b);
		a = dp[0][a];
		b = dp[0][b];
	}
	res = max(res , a);
	return res;
}
/*void put(int a , int b , int val){
	int dif = depth[a] - depth[b];
	if(dif < 0){
		swap(a , b);
		dif = -dif;
	}
	for(int i = 0 ; i < LN ; ++i){
		if((dif >> i) & 1){
			res[i][a] = min(res[i][a] , val);
			a = dp[i][a];
		}
	}
	if(a != b){
		for(int i = LN - 1 ; i >= 0 ; --i){
			if(dp[i][a] != dp[i][b]){
				res[i][a] = min(res[i][a] , val);
				res[i][b] = min(res[i][b] , val);
				a = dp[i][a];
				b = dp[i][b];
			}
		}
		res[1][a] = min(res[1][a] , val);
		res[1][b] = min(res[1][b] , val);
		a = dp[0][a];
		b = dp[0][b];
	}
	res[0][a] = min(res[0][a] , val);
}*/
int rgt[N];
int q;
int l[N] , r[N];
vector < int > ask[N];
long long bit1[N];
long long bit2[N];
long long bit3[N];
long long ans[N];
void update(long long bit[] , int idx , int val){
	while(idx <= n){
		bit[idx] += val;
		idx += idx & -idx;
	}
}
long long query(long long bit[] , int idx){
	long long res = 0;
	while(idx){
		res += bit[idx];
		idx -= idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , a + i , b + i);
		if(a[i] > b[i]){
			swap(a[i] , b[i]);
		}
		g[a[i]].emplace_back(b[i]);
	}
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
	}
	for(int i = n ; i >= 1 ; --i){
		for(int j : g[i]){
			if(find(i) != find(j)){
				v[i].emplace_back(j);
				v[j].emplace_back(i);
				parent[find(j)] = find(i);
			}
			else{
				cycle.emplace_back(make_pair(i , j));
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(depth[i] == 0){
			depth[i] = 1;
			dfs(i , 0);
		}
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		val[0][i] = i;
	}
	for(int i = 1 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			val[i][j] = max(val[i - 1][j] , val[i - 1][dp[i - 1][j]]);
		}
	}
	/*for(int i = 0 ; i < LN ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			res[i][j] = n + 1;
		}
	}*/
	for(int i = 1 ; i <= n ; ++i){
		rgt[i] = n + 1;
	}
	for(auto it : cycle){
		int a = it.first;
		int b = it.second;
		int val = get(a , b);
		//put(a , b , val);
		rgt[a] = min(rgt[a] , val);
	}
	/*for(int i = LN - 1 ; i >= 1 ; --i){
		for(int j = 1 ; j <= n ; ++j){
			res[i - 1][j] = min(res[i - 1][j] , res[i][j]);
			res[i - 1][dp[i - 1][j]] = min(res[i - 1][dp[i - 1][j]] , res[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		rgt[i] = res[0][i];
	}*/
	for(int i = n - 1 ; i >= 1 ; --i){
		rgt[i] = min(rgt[i] , rgt[i + 1]);
	}
	for(int i = 1 ; i <= n ; ++i){
		--rgt[i];
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , l + i , r + i);
		ask[l[i]].emplace_back(i);
		ask[r[i] + 1].emplace_back(-i);
	}
	for(int i = n ; i >= 1 ; --i){
		update(bit1 , rgt[i] , rgt[i] - i + 1);
		update(bit2 , rgt[i] , 1);
		update(bit3 , rgt[i] , i);
		for(int idx : ask[i]){
			int l = ::l[abs(idx)];
			int r = ::r[abs(idx)];
			int sign = 1;
			if(idx < 0){
				sign = -1;
			}
			ans[abs(idx)] += sign * (query(bit1 , r) + (query(bit2 , n) - query(bit2 , r)) * (r + 1LL) - (query(bit3 , n) - query(bit3 , r)));
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%lld\n" , ans[i]);
	}
}