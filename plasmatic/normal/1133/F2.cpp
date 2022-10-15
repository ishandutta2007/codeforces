//============================================================================
// Name        : 544F2.cpp
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
int n, m, d, ba, bb;
vector<int> components,
    matrix[MAX];
vector<p> edges;
bool vis[MAX], notAllowed[MAX];

void dfs(int cur, int par){
	if(cur == 1) return;

	vis[cur] = true;

	for (int adj : matrix[cur])
		if(!vis[adj])
			dfs(adj, cur);
}

void dfs2(int cur, int par){
    if(notAllowed[cur] && par != -1) return;
    
    vis[cur] = true;
    
    for (int adj : matrix[cur])
		if(!vis[adj])
			dfs2(adj, cur);
	
	if(par != -1)
	    printf("%d %d\n", par, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> d;

	for (int i = 0; i < m; ++i) {
		cin >> ba >> bb;
		matrix[ba].push_back(bb);
		matrix[bb].push_back(ba);
	}

	int sz = matrix[1].size();

	if(sz < d){
	    printf("NO\n");
	    return 0;
	}
	
	vector<int> adjs = matrix[1];
	
	// count components
	for(int adj : adjs){
	    if(!vis[adj]){
	        components.push_back(adj);
	        dfs(adj, -1);
	    }
	}
	
	if(components.size() > (size_t)d){
	    printf("NO\n");
	    return 0;
	}
	
	// add extra if needed
	for(int comp : components)
	    notAllowed[comp] = true;
	
	for(int adj : adjs){
	    if(components.size() >= (size_t)d)
	        break;
	    
	    if(!notAllowed[adj]){
	        components.push_back(adj);
	        notAllowed[adj] = true;
	    }
	}
	
	// constructive dfs
	
	printf("YES\n");
	
	for(int comp : components)
	    printf("1 %d\n", comp);
	
	memset(vis, false, sizeof vis);
	notAllowed[1] = true;
	for(int comp : components)
	    dfs2(comp, -1);
	
	return 0;
}