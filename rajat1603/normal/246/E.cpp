#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
char tmp[24];
map < string , int > mp;
int val[N];
vector < int > v[N];
int inp;
int cur = 0;
int tin[N];
int tout[N];
int rev[N];
int depth[N];
vector < int > nodes[N];
int rdcomp[N];
int rdtimer = 0;
int arr[N];
vector < pair < int , int > > idx[N];
int timer = 0;
int q;
int vi , ki;
int bit[N];
int pre[N];
int ans[N];
void dfs(int node){
	tin[node] = ++timer;
	rev[timer] = node;
	nodes[depth[node]].emplace_back(tin[node]);
	for(int next : v[node]){
		depth[next] = depth[node] + 1;
		dfs(next);
	}
	tout[node] = timer;
}
void update(int idx , int val){
	while(idx){
		bit[idx] += val;
		idx -= idx & -idx;
	}
}
int query(int idx){
	int res = 0;
	while(idx <= n){
		res += bit[idx];
		idx += idx & -idx;
	}
	return res;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s %d" , tmp , &inp);
		v[inp].emplace_back(i);
		if(mp.find(tmp) == mp.end()){
			mp[tmp] = ++cur;
		}
		val[i] = mp[tmp];
	}
	depth[0] = 0;
	dfs(0);
	for(int i = 1 ; i <= n ; ++i){
		for(int x : nodes[i]){
			rdcomp[rev[x]] = ++rdtimer;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		arr[rdcomp[i]] = val[i];
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &vi , &ki);
		if(depth[vi] + ki > N){
			ans[i] = 0;
			continue;
		}
		auto it1 = lower_bound(nodes[depth[vi] + ki].begin() , nodes[depth[vi] + ki].end() , tin[vi]);
		auto it2 = upper_bound(nodes[depth[vi] + ki].begin() , nodes[depth[vi] + ki].end() , tout[vi]);
		if(it1 == it2){
			ans[i] = 0;
		}
		else{
			--it2;
			idx[rdcomp[rev[*it2]]].emplace_back(make_pair(rdcomp[rev[*it1]] , i));
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		update(pre[arr[i]] , -1);
		update(i , 1);
		pre[arr[i]] = i;
		for(auto it : idx[i]){
			ans[it.second] = query(it.first);
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}