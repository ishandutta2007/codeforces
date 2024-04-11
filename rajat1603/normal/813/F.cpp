#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
int x[N] , y[N];
int match[N];
int parent[N];
bool sum[N];
int siz[N];
vector < int > comp[N];
map < int , int > mp[N];
int ans[N];
pair < int , bool > find(int node){
	bool res = sum[node];
	while(parent[node] != node){
		node = parent[node];
		res ^= sum[node];
	}
	return {node , res};
}
void solve(int l , int r , vector < int > &edge , bool rekt){
	if(rekt){
		for(int i = l ; i <= r ; ++i){
			ans[i] = 0;
		}
		return;
	}
	vector < pair < int , int > > vv1;
	vv1.clear();
	for(int e : edge){
		int x = ::x[e];
		int y = ::y[e];
		auto A = find(x);
		auto B = find(y);
		int a = A.first;
		int b = B.first;
		bool same = A.second == B.second;
		if(a == b){
			if(same){
				rekt = 1;
				break;
			}
		}
		else{
			if(siz[a] < siz[b]){
				swap(a , b);
				swap(x , y);
			}
			siz[a] += siz[b];
			parent[b] = a;
			sum[b] = same;
			vv1.push_back({b , a});
		}
	}
	if(rekt){
		for(int i = l ; i <= r ; ++i){
			ans[i] = 0;
		}
		reverse(vv1.begin() , vv1.end());
		for(auto it : vv1){
			parent[it.first] = it.first;
			sum[it.first] = 0;
			siz[it.second] -= siz[it.first];
		}
		return;
	}
	if(l == r){
		ans[l] = 1;
	}
	else{
		edge.clear();
		int mid = l + r >> 1;
		for(int i = mid + 1 ; i <= r ; ++i){
			if(match[i] <= l){
				edge.push_back(i);
			}
		}
		solve(l , mid , edge , 0);
		edge.clear();
		for(int i = l + 1 ; i <= mid + 1 ; ++i){
			if(match[i] > r){
				edge.push_back(i);
			}
		}
		solve(mid + 1 , r , edge , 0);
	}
	reverse(vv1.begin() , vv1.end());
	for(auto it : vv1){
		parent[it.first] = it.first;
		sum[it.first] = 0;
		siz[it.second] -= siz[it.first];
	}
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , x + i , y + i);
		if(x[i] > y[i]){
			swap(x[i] , y[i]);
		}
		if(mp[x[i]].find(y[i]) == mp[x[i]].end()){
			mp[x[i]][y[i]] = i;
		}
		else{
			match[i] = mp[x[i]][y[i]];
			match[match[i]] = i;
			mp[x[i]].erase(y[i]);
		}
	}
	int ori = m;
	for(int i = 1 ; i <= n ; ++i){
		for(auto it : mp[i]){
			++m;
			x[m] = i;
			y[m] = it.first;
			match[it.second] = m;
			match[m] = it.second;
		}
		mp[i].clear();
	}
	for(int i = 1 ; i <= n ; ++i){
		parent[i] = i;
		siz[i] = 1;
		sum[i] = 0;
		comp[i].clear();
		comp[i].push_back(i);
	}
	vector < int > v;
	v.clear();
	solve(1 , m , v , 0);
	for(int i = 1 ; i <= ori ; ++i){
		puts(ans[i] ? "YES" : "NO");
	}
}