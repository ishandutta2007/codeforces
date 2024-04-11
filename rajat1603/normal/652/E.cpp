#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m;
int a[N];
int b[N];
int c[N];
vector < int > v[N];
bool visited[N];
int tin[N];
int anc[N];
int timer = 0;
int bridge[N];
int comp[N];
int cur = 0;
bool ok[N];
vector < pair < int , int > > v2[N];
int depth[N];
int baap[N];
int badiya[N];
int x , y;
void dfs(int node , int last){
	visited[node] = 1;
	tin[node] = anc[node] = ++timer;
	for(int edge : v[node]){
		if(last == edge){
			continue;
		}
		int next = a[edge] ^ b[edge] ^ node;
		if(!visited[next]){
			dfs(next , edge);
			anc[node] = min(anc[node] , anc[next]);
		}
		else{
			anc[node] = min(anc[node] , tin[next]);
		}
		if(anc[next] > tin[node]){
			bridge[edge] = 1;
		}
	}
}
void dfs2(int node){
	comp[node] = cur;
	visited[node] = 1;
	for(int edge : v[node]){
		if(bridge[edge]){
			continue;
		}
		if(c[edge]){
			ok[cur] = 1;
		}
		int next = a[edge] ^ b[edge] ^ node;
		if(!visited[next]){
			dfs2(next);
		}
	}
}
void dfs3(int node , int baap){
	depth[node] = depth[baap] + 1;
	::baap[node] = baap;
	for(auto next : v2[node]){
		if(next.first != baap){
			badiya[next.first] = next.second;
			dfs3(next.first , node);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d %d" , a + i , b + i , c + i);
		v[a[i]].emplace_back(i);
		v[b[i]].emplace_back(i);
	}
	dfs(1 , 0);
	memset(visited , 0 , sizeof(visited));
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			++cur;
			dfs2(i);
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		if(bridge[i]){
			v2[comp[a[i]]].emplace_back(make_pair(comp[b[i]] , c[i]));
			v2[comp[b[i]]].emplace_back(make_pair(comp[a[i]] , c[i]));
		}
	}
	dfs3(1 , 0);
	scanf("%d %d" , &x , &y);
	x = comp[x];
	y = comp[y];
	while(x != y){
		if(depth[x] < depth[y]){
			swap(x , y);
		}
		if(ok[x] || badiya[x]){
			cout << "YES\n";
			return 0;
		}
		x = baap[x];
	}
	if(ok[x]){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}