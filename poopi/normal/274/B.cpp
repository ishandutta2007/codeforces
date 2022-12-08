										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int64, int64>

int n;
vector <int> adj[100010];
int64 v[100010];

P dfs(int idx, int par){
	int64 mn = 0, mx = 0;
	for(int i = 0; i < adj[idx].size(); i++){
		int j = adj[idx][i];
		if(j == par) continue;
		P tmp = dfs(j, idx);
		mn = max(mn, tmp.first);
		mx = max(mx, tmp.second);
	}
	int64 d = v[idx] + mx - mn;
	if(d < 0)
		mx += -d;
	else mn += d;
	return P(mn, mx);
}

int main(){
	cin >> n;
	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
		cin >> v[i];
	P res = dfs(0, -1);
	cout << res.first + res.second << endl;
	return 0;
}