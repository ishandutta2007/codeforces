#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<int> ice[n];
	vector<int> g[n];
	int ma = 0;
	int pos = -1;
	
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		if(x >= ma){
			ma = x;
			pos = i;
		}
		
		for(int j = 0; j<x; j++){
			int y;
			cin >> y;
			ice[i].push_back(y);
		}
	}
	
	int col[m + 1];
	fill(col, col + m + 1, -1);
	
	int cnt = 1;
	for(int x: ice[pos]){
		col[x] = cnt;
		cnt++;
	}
	cnt--;
	
	for(int i = 0; i<n - 1; i++){
		int x, y;
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	
	int vis[n];
	fill(vis, vis + n, 0);
	vis[pos] = 1;
	vector<int> dfs;
	dfs.push_back(pos);
	set<int> cur_col;
	
	while(!dfs.empty()){
		int x = dfs.back();
		dfs.pop_back();
		cur_col.clear();
		
		for(int ic: ice[x]){
			if(col[ic] != -1) cur_col.insert(col[ic]);
		}
		
		int ptr = 1;
		
		for(int ic: ice[x]){
			if(col[ic] == -1){
				while(cur_col.count(ptr)) ptr++;
				cur_col.insert(ptr);
				col[ic] = ptr;
			}
		}
		
		for(int vert: g[x]){
			if(!vis[vert]){
				vis[vert] = 1;
				dfs.push_back(vert);
			}
		}
	}
	
	for(int i = 1; i<=m; i++){
		if(col[i] == -1) col[i] = 1;
	}
	
	cout << max(cnt, 1) << endl;
	for(int i = 1; i<=m; i++){
		cout << col[i] << " ";
	}
	
	
	
}