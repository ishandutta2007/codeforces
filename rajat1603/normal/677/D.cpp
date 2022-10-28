#include "bits/stdc++.h"
using namespace std;
const int N = 305;
const int P = N * N;
const int inf = 1e9;
int n , m , p;
int arr[N][N];
int dp[N][N];
vector < pair < int , int > > v[P];
vector < pair < int , int > > tmp;
int bit1[N];
int bit2[N];
int ans;
void update1(int idx , int val){
	while(idx <= m){
		bit1[idx] = min(bit1[idx] , val);
		idx += idx & -idx;
	}
}
void update2(int idx , int val){
	while(idx){
		bit2[idx] = min(bit2[idx] , val);
		idx -= idx & -idx;
	}
}
int query1(int idx){
	int res = inf;
	while(idx){
		res = min(res , bit1[idx]);
		idx -= idx & -idx;
	}
	return res;
}
int query2(int idx){
	int res = inf;
	while(idx <= m){
		res = min(res , bit2[idx]);
		idx += idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d %d %d" , &n , &m , &p);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d" , &arr[i][j]);
			dp[i][j] = inf;
		}
	}
	for(int i = 1 ; i <= p ; ++i){
		v[i].clear();
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			v[arr[i][j]].emplace_back(make_pair(i , j));
		}
	}
	for(auto it : v[1]){
		dp[it.first][it.second] = it.first - 1 + it.second - 1;
	}
	for(int i = 2 ; i <= p ; ++i){
		tmp.clear();
		for(int j = 1 ; j <= m ; ++j){
			bit1[j] = inf;
			bit2[j] = inf;
		}
		for(auto it : v[i - 1]){
			tmp.emplace_back(it);
		}
		for(auto it : v[i]){
			tmp.emplace_back(it);
		}
		sort(tmp.begin() , tmp.end());
		for(auto it : tmp){
			if(arr[it.first][it.second] == i - 1){
				update1(it.second , dp[it.first][it.second] - it.first - it.second);
				update2(it.second , dp[it.first][it.second] + it.second - it.first);
			}
			else{
				dp[it.first][it.second] = min(dp[it.first][it.second] , min(query1(it.second) + it.first + it.second , query2(it.second) + it.first - it.second));
			}
		}
		for(int j = 1 ; j <= m ; ++j){
			bit1[j] = inf;
			bit2[j] = inf;
		}
		reverse(tmp.begin() , tmp.end());
		for(auto it : tmp){
			if(arr[it.first][it.second] == i - 1){
				update1(it.second , dp[it.first][it.second] + it.first - it.second);
				update2(it.second , dp[it.first][it.second] + it.second + it.first);
			}
			else{
				dp[it.first][it.second] = min(dp[it.first][it.second] , min(query1(it.second) - it.first + it.second , query2(it.second) - it.first - it.second));
			}
		}
	}
	ans = inf;
	for(auto it : v[p]){
		ans = min(ans , dp[it.first][it.second]);
	}
	printf("%d\n" , ans);
}