										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n;
vector <int> adj[100010];
int deg[100010];
int dist[100010];
bool mark[100010];

void dfs(int idx){
	mark[idx] = true;

	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(!mark[v]){
			dist[v] = dist[idx] + 1;
			dfs(v);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++, deg[b]++;
	}

	dfs(0);
	bool leaf[2] = {};
	for(int i = 0; i < n; i++){
		if(deg[i] == 1) leaf[dist[i] % 2] = true;
	}
	int mn = (leaf[0] && leaf[1]) ? 3 : 1;

	int mx = n - 1;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < adj[i].size(); j++){
			if(deg[adj[i][j]] == 1) cnt++;
		}
		if(cnt > 1)
			mx -= cnt - 1;
	}
	cout << mn << ' ' << mx << endl;
	return 0;
}