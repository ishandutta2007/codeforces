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
#define P pair<int, int>

int n, m;
int tot[200010], in[200010];
int pnt, pl[200010];
vector <P> edge;
vector <P> adj[200010];

void dfs(int idx){
	if(idx == n - 1)
		return;
	pl[idx] = pnt++;
	for(int i = 0; i < adj[idx].size(); i++){
		int j = adj[idx][i].first;
		in[j] += adj[idx][i].second;
		if(2 * in[j] == tot[j] && pl[j] == -1)
			dfs(j);
	}
}

int main(){
	cin >> n >> m;
	int a, b, c;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		a--, b--;
		tot[a] += c;
		tot[b] += c;
		edge.push_back(P(a, b));
		adj[a].push_back(P(b, c));
		adj[b].push_back(P(a, c));
	}
	memset(pl, -1, sizeof pl);
	dfs(0);
	pl[n - 1] = n - 1;
	for(int i = 0; i < m; i++)
		cout << (pl[edge[i].first] < pl[edge[i].second] ? 0 : 1) << endl;
	return 0;
}