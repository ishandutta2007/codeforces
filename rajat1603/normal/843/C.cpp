#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b;
vector < int > v[N];
int subtree[N];
void dfs1(int node , int parent){
	subtree[node] = 1;
	for(int next : v[node]){
		if(next != parent){
			dfs1(next , node);
			subtree[node] += subtree[next];
		}
	}
}
int find(int node , int parent){
	for(int next : v[node]){
		if(next != parent && subtree[next] > (n >> 1)){
			return find(next , node);
		}
	}
	return node;
}
vector < pair < int , pair < int , int > > > ans;
int root , cur , who;
void dfs2(int node , int parent){
	//cout << node << " " << parent << " " << cur << " " << who << endl;
	ans.push_back({root , {cur , node}});
	ans.push_back({node , {parent , who}});
	cur = node;
	for(int next : v[node]){
		if(next != parent){
			dfs2(next , node);
		}
	}
}
void actuallysolve(int child , int node){
	root = node;
	cur = child;
	who = child;
	for(int next1 : v[child]){
		if(next1 != node){
			for(int next2 : v[next1]){
				if(next2 != child){
					dfs2(next2 , next1);
				}
			}
		}
	}
	ans.push_back({root , {cur , who}});
}
void solve(int node , int parent){
	for(int next : v[node]){
		if(next != parent){
			actuallysolve(next , node);
		}
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs1(1 , 0);
	int cent = find(1 , 0);
	int cent2 = 0;
	for(int next : v[cent]){
		if(subtree[next] * 2 == n){
			cent2 = next;
		}
	}
	solve(cent , cent2);
	if(cent2){
		solve(cent2 , cent);
	}
	printf("%d\n" , int(ans.size()));
	for(auto it : ans){
		printf("%d %d %d\n" , it.first , it.second.first , it.second.second);
	}
}