//============================================================================
// Name        : 544F.cpp
// Author      : Daxi the Taxi
// Version     :
// Copyright   : ALL YOUR CODE IS BELONG TO US
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

const int MAX = 200001;
int n, m, ba, bb, beste = 0, besti = -1;
vector<int> matrix[MAX];
bool vis[MAX];

void dfs(int cur, int par){
	vis[cur] = true;

	for (int adj : matrix[cur])
		if(!vis[adj])
			dfs(adj, cur);

	if(par != -1)
		printf("%d %d\n", par, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> ba >> bb;
		matrix[ba].push_back(bb);
		matrix[bb].push_back(ba);
	}

	for (int i = 1; i <= n; ++i) {
		int sz = matrix[i].size();
		if(sz > beste){
			beste = sz;
			besti = i;
		}
	}

	vis[besti] = true;
	for (int adj : matrix[besti]){
		vis[adj] = true;
		printf("%d %d\n", besti, adj);
	}

	for (int adj : matrix[besti])
		dfs(adj, -1);
}