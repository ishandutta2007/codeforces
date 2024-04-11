#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n;
int l[N] , r[N];
vector < int > tmp;
vector < pair < int , int > > v[N];
int col[N];
int deg[N];
int dest;
void dfs(int node){
	while(!v[node].empty()){
		auto next = v[node].back();
		v[node].pop_back();
		if(col[next.second]){
			continue;
		}
		col[next.second] = 1 + (next.first > node);
		--deg[node];
		--deg[next.first];
		if(next.first == dest){
			break;
		}
		dfs(next.first);
		break;
	}
}
void solve(int node){
	dest = node;
	dfs(node);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , l + i , r + i);
		++r[i];
		tmp.emplace_back(l[i]);
		tmp.emplace_back(r[i]);
	}
	sort(tmp.begin() , tmp.end());
	tmp.resize(unique(tmp.begin() , tmp.end()) - tmp.begin());
	for(int i = 1 ; i <= n ; ++i){
		l[i] = lower_bound(tmp.begin() , tmp.end() , l[i]) - tmp.begin() + 1;
		r[i] = lower_bound(tmp.begin() , tmp.end() , r[i]) - tmp.begin() + 1;
	}
	tmp.clear();
	for(int i = 1 ; i <= n ; ++i){
		++deg[l[i]];
		++deg[r[i]];
		v[l[i]].emplace_back(make_pair(r[i] , i));
		v[r[i]].emplace_back(make_pair(l[i] , i));
	}
	for(int i = 1 ; i < N ; ++i){
		if(deg[i] & 1){
			tmp.emplace_back(i);
		}
	}
	int ori = n;
	for(int i = 1 ; i < tmp.size() ; i += 2){
		++n;
		l[n] = tmp[i - 1];
		r[n] = tmp[i];
		++deg[l[n]];
		++deg[r[n]];
		v[l[n]].emplace_back(make_pair(r[n] , n));
		v[r[n]].emplace_back(make_pair(l[n] , n));
	}
	for(int i = 1 ; i < N ; ++i){
		while(deg[i]){
			solve(i);
		}
	}
	for(int i = 1 ; i <= ori ; ++i){
		printf("%d%c" , col[i] - 1 , " \n"[i == ori]);
	}
}