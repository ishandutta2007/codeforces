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
#define Max 100010

int n, m;
vector <int> adj[Max];
vector <int> rev[Max];
int st[Max];
bool mark1[Max], mark2[Max];

void dfs1(int idx){
	mark1[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++){
		int j = adj[idx][i];
		if(!mark1[j])
			dfs1(j);
	}
}

void dfs2(int idx){
	mark2[idx] = true;
	if(st[idx] == 1)
		return;
	for(int i = 0; i < rev[idx].size(); i++){
		int j = rev[idx][i];
		if(!mark2[j])
			dfs2(j);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		scanf("%d", &st[i]);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
		if(st[i] == 1 && !mark1[i])
			dfs1(i);
	for(int i = 0; i < n; i++)
		if(st[i] == 2 && !mark2[i])
			dfs2(i);
	for(int i = 0; i < n; i++)
		cout << (mark1[i] && mark2[i] ? 1 : 0) << endl;
	return 0;
}