#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > v[N];
int a[N];
int b[N];
int col[N];
int visited[N];
int comps[N];
int cur;
vector < int > g[N];
int color[N];
int sz[N];
bool rekt;
int num;
int compwhite[N];
int compblack[N];
void dfs(int node){
	comps[node] = cur;
	visited[node] = 1;
	++sz[cur];
	for(int edge : v[node]){
		int next = a[edge] ^ b[edge] ^ node;
		if(!visited[next] && col[edge]){
			dfs(next);
		}
	}
}
void dfs2(int node){
	visited[node] = num;
	if(color[node] == 0){
		compblack[num] += sz[node];
	}
	else{
		compwhite[num] += sz[node];
	}
	for(int next : g[node]){
		if(color[next] == -1){
			color[next] = !color[node];
			dfs2(next);
		}
		else if(color[next] == color[node]){
			rekt = 1;
		}
	}
}
vector < int > solve(){
	memset(visited , 0 , sizeof(visited));
	cur = 0;
	memset(sz , 0 , sizeof(sz));
	rekt = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			++cur;
			dfs(i);
		}
	}
	for(int i = 1 ; i <= cur ; ++i){
		g[i].clear();
		color[i] = -1;
	}
	for(int i = 1 ; i <= m ; ++i){
		if(!col[i]){
			g[comps[a[i]]].emplace_back(comps[b[i]]);
			g[comps[b[i]]].emplace_back(comps[a[i]]);
		}
	}
	memset(visited , 0 , sizeof(visited));
	num = 0;
	memset(compblack , 0 , sizeof(compblack));
	memset(compwhite , 0 , sizeof(compwhite));
	for(int i = 1 ; i <= cur ; ++i){
		if(!visited[i]){
			++num;
			color[i] = 0;
			dfs2(i);
		}
	}
	if(rekt){
		vector < int > t;
		t.resize(1);
		t[0] = -1;
		return t;
	}
	vector < int > ans;
	ans.clear();
	for(int i = 1 ; i <= n ; ++i){
		int node = comps[i];
		int group = visited[node];
		if(compblack[group] < compwhite[group]){
			if(!color[node]){
				ans.emplace_back(i);
			}
		}
		else{
			if(color[node]){
				ans.emplace_back(i);
			}
		}
	}
	return ans;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		char tmp[3];
		scanf("%d %d %s" , a + i , b + i , tmp);
		col[i] = (tmp[0] == 'R');
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	vector < int > ans1 = solve();
	for(int i = 1 ; i <= m ; ++i){
		col[i] ^= 1;
	}
	vector < int > ans2 = solve();
	if(ans1.empty() || ans2.empty()){
		printf("0\n");
		return 0;
	}
	else if((ans1.size() > ans2.size() || ans1[0] == -1) && ans2[0] != -1){
		swap(ans1 , ans2);
	}
	if(ans1[0] == -1){
		printf("-1\n");
		return 0;
	}
	printf("%d\n" , int(ans1.size()));
	for(int x : ans1){
		printf("%d " , x);
	}
}