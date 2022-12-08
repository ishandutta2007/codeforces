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

#pragma comment(linker, "/STACK:50000000")

#define int64 long long
#define P pair<int, int>
#define Max 50010

int n, k, res;
vector <int> adj[Max];
int cnt[Max][510];

void dfs(int idx, int par){
	cnt[idx][0] = 1;
	for(int i = 0; i < adj[idx].size(); i++){
		int j = adj[idx][i];
		if(j != par){
			dfs(j, idx);
			for(int l = 1; l <= k; l++)
				res += cnt[idx][k - l] * cnt[j][l - 1];
			for(int l = 0; l < k; l++)
				cnt[idx][l + 1] += cnt[j][l];
		}
	}
}

int main(){
	while(cin >> n >> k){
		int a, b;
		res = 0;
		for(int i = 0; i < n; i++)
			if(!adj[i].empty())
				adj[i].clear();
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < n - 1; i++){
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(0, -1);
		cout << res << endl;
	}
	return 0;
}