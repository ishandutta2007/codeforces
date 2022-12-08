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
bool mark[10010];
vector <int> adj[10010];

void dfs(int idx){
	mark[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(!mark[v])
			dfs(v);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		adj[i].push_back(t - 1);
		adj[t - 1].push_back(i);
	}

	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}