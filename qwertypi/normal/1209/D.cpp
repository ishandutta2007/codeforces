#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

using namespace std;

typedef long long ll;
vvi graph(100000);
bool visited[100000];
int dfs(int st){
	int cnt = 0;
	vector<int> Stack{st};
	while(Stack.size()){
		int op = Stack.back();
		Stack.pop_back();
		if(visited[op])
			continue;
		cnt++;
		visited[op] = 1;
		for(auto i:graph[op]){
			Stack.emplace_back(i);
		}
	}
	return cnt;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		graph[v1].emplace_back(v2);
		graph[v2].emplace_back(v1);
	}
	int ans = 0;
	fill(visited, visited + n, 0);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			ans += dfs(i) - 1;
		}
	}
	cout << m - ans;
	return 0;
}