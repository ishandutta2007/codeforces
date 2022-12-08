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

int n, k, p;
vector <int> adj[100010];
vector <int> d;

void dfs(int idx, int par, int dep){
	d.push_back(dep);
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v != par)
			dfs(v, idx, dep + 1);
	}
}

int main(){
	cin >> n >> k >> p;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1, 0);
	sort(d.begin(), d.end());
	d.push_back(d[d.size() - 1]);

	int cur = 1, mx = 0;
	for(int end = n - 1, str = n - 1; end > 0; end--){
		cur--;
		p += cur * (d[end + 1] - d[end]);
		while(str > 0 && p >= d[end] - d[str]){
			cur++;
			p -= d[end] - d[str--];
		}
		mx = max(mx, cur);
	}
	cout << min(mx, k) << endl;
	return 0;
}