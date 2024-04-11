#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[200001];
vector<vector<int>> G(200001);
int Size[1001];
 
void dfs2(int x, int p = -1){
	int res = 1;
	for(auto i : G[x]){
		if(i != p){
			dfs2(i, x);
			res += Size[i];
		}
	}
	Size[x] = res;
}
 
set<int> ans;
void test(int x, int y, int z){
	cout << "? " << x << ' ' << z << endl;
	int verdict;
	cin >> verdict;
	if(x != verdict){
		ans.erase(x);
	}
	if(y != verdict){
		ans.erase(y);
	}
	if(z != verdict){
		ans.erase(z);
	}
}
 
bool visited[1001];
void dfs(int x, int p = -1){
	visited[x] = 1;
	vector<int> odd, even;
	for(auto i : G[x]){
		if(!visited[i]){
			if(Size[i] % 2){
				odd.push_back(i);
			}else{
				even.push_back(i);
			}
		}
	}
	if(p == -1){
		for(int i = 0; i < odd.size() / 2; i++){
			test(odd[i * 2], x, odd[i * 2 + 1]);
			dfs(odd[i * 2], -1);
			dfs(odd[i * 2 + 1], -1);
		}
		if(odd.size() % 2){
			dfs(odd[odd.size() - 1], x);
		}
		for(auto i : even){
			dfs(i, x);
		}
	}else{
		for(int i = 0; i < odd.size() / 2; i++){
			test(odd[i * 2], x, odd[i * 2 + 1]);
			dfs(odd[i * 2], -1);
			dfs(odd[i * 2 + 1], -1);
		}
		if(odd.size() % 2){
			test(odd[odd.size() - 1], x, p);
			dfs(odd[odd.size() - 1], -1);
			for(auto i : even){
				dfs(i, x);
			}
		}else if(even.size()){
			test(even[0], x, p);
			dfs(even[0], -1);
			for(int i = 1; i < even.size(); i++){
				dfs(even[i], x);
			}
		}else if(odd.size()){
			test(odd[0], x, p);
		}else{
			test(x, -1, p);
		}
	}
}
 
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs2(1);
	for(int i = 1; i <= n; i++){
		ans.insert(i);
	}
	dfs(1);
	for(auto i : ans){
		cout << "! " << i << ' ';
	}
}