#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n , m;
int a[N] , b[N];
vector < int > v[N];
set < int > s[N];
int parent[N];
vector < vector < int > > ans;
int depth[N];
vector < int > levels[N];
bool visited[N];
bool done[N];
void dfs(int node , int parent , int dist){
	::parent[node] = parent;
	depth[node] = dist;
	levels[dist].emplace_back(node);
	for(int next : v[node]){
		if(next == parent){
			continue;
		}
		if(visited[next]){
			s[node].insert(next);
		}
		else{
			visited[next] = 1;
			dfs(next , node , dist + 1);
		}
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , a + i , b + i);
		v[a[i]].emplace_back(b[i]);
		v[b[i]].emplace_back(a[i]);
	}
	ans.clear();
	for(int i = 1 ; i <= n ; ++i){
		if(!visited[i]){
			visited[i] = 1;
			dfs(i , 0 , 0);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		while(s[i].size() > 1){
			int a = *s[i].begin();
			s[i].erase(s[i].begin());
			int c = *s[i].begin();
			s[i].erase(s[i].begin());
			ans.push_back({a , i , c});
			s[a].erase(i);
			s[c].erase(i);
		}
	}
	for(int i = n ; i >= 1 ; --i){
		vector < pair < int , int > > tmp;
		tmp.clear();
		for(int x : levels[i]){
			if(done[x]){
				continue;
			}
			if(!s[x].empty()){
				ans.push_back({parent[x] , x , *s[x].begin()});
				s[*s[x].begin()].erase(x);
				s[x].clear();
			}
			else{
				tmp.push_back({parent[x] , x});
			}
		}
		sort(tmp.begin() , tmp.end());
		vector < int > rip;
		rip.clear();
		for(int i = 0 ; i < tmp.size() ; ++i){
			if(i + 1 < tmp.size()){
				if(tmp[i + 1].first == tmp[i].first){
					ans.push_back({tmp[i].second , tmp[i].first , tmp[i + 1].second});
					++i;
				}
				else{
					rip.emplace_back(tmp[i].second);
				}
			}
			else{
				rip.push_back(tmp[i].second);
			}
		}
		for(int x : rip){
			int y = parent[x];
			if(s[y].empty()){
				if(parent[y]){
					ans.push_back({parent[y] , y , x});
					done[y] = 1;
				}
			}
			else{
				ans.push_back({*s[y].begin() , y , x});
				s[*s[y].begin()].erase(y);
				s[y].clear();
			}
		}
	}
	printf("%d\n" , int(ans.size()));
	for(auto it : ans){
		printf("%d %d %d\n" , it[0] , it[1] , it[2]);
	}
}