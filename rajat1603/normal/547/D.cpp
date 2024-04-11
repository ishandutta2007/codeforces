#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n;
int x[N] , y[N];
int col[N];
vector < pair < int , int > > v[2][N];
int degree[2][N];
vector < int > tmp;
pair < bool , int > dest;
void dfs(bool side , int node , int level){
	while(!v[side][node].empty()){
		auto next = v[side][node].back();
		v[side][node].pop_back();
		if(col[next.second]){
			continue;
		}
		col[next.second] = 1 + level;
		--degree[side][node];
		--degree[!side][next.first];
		if(!side == dest.first && next.first == dest.second){
			break;
		}
		dfs(!side , next.first , !level);
		break;
	}
}
void solve(pair < bool , int > start , pair < bool , int > finish){
	dest = finish;
	dfs(start.first , start.second , 0);
}
int main(){
	scanf("%d" , &n);
	int nn = n;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , x + i , y + i);
		v[0][x[i]].emplace_back(make_pair(y[i] , i));
		v[1][y[i]].emplace_back(make_pair(x[i] , i));
		++degree[0][x[i]];
		++degree[1][y[i]];
	}
	for(int i = 1 ; i < N ; ++i){
		if(degree[0][i] & 1){
			tmp.emplace_back(i);
		}
	}
	for(int i = 1 ; i < N ; ++i){
		if(degree[1][i] & 1){
			if(tmp.empty()){
				++n;
				x[n] = N - 1;
				y[n] = i;
			}
			else{
				++n;
				x[n] = tmp.back();
				y[n] = i;
				tmp.pop_back();
			}
			v[0][x[n]].emplace_back(make_pair(y[n] , n));
			v[1][y[n]].emplace_back(make_pair(x[n] , n));
			++degree[0][x[n]];
			++degree[1][y[n]];
		}
	}
	for(int a : tmp){
		++n;
		x[n] = a;
		y[n] = N - 1;
		v[0][x[n]].emplace_back(make_pair(y[n] , n));
		v[1][y[n]].emplace_back(make_pair(x[n] , n));
		++degree[0][x[n]];
		++degree[1][y[n]];
	}
	for(int i = 1 ; i < N ; ++i){
		while(degree[0][i]){
			solve(make_pair(0 , i) , make_pair(0 , i));
		}
	}
	for(int i = 1 ; i < N ; ++i){
		while(degree[1][i]){
			solve(make_pair(1 , i) , make_pair(1 , i));
		}
	}
	for(int i = 1 ; i <= nn ; ++i){
		printf("%c" , " rb"[col[i]]);
	}
	printf("\n");
}