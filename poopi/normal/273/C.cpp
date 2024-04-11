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
int gr[300010];
int cnt[300010];
vector <int> adj[300010];
queue <int> q;

int main(){
	scanf("%d%d", &n, &m);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
		cnt[i] = adj[i].size();
		if(cnt[i] > 1)
			q.push(i);
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		if(cnt[v] <= 1)
			continue;
		gr[v] = 1 - gr[v];
		cnt[v] = adj[v].size() - cnt[v];
		for(int i = 0; i < adj[v].size(); i++){
			int u = adj[v][i];
			if(gr[u] == gr[v]){
				if(++cnt[u] > 1)
					q.push(u);
			}
			else cnt[u]--;
		}
	}
	for(int i = 0; i < n; i++)
		cout << gr[i];
	cout << endl;
	return 0;
}