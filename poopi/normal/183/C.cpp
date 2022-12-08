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

int n, m, res;
int num[100010];
bool mark[100010];
vector <int> adj[100010];
vector <int> rev[100010];

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a % b));
}

void dfs(int idx, int x){
	if(mark[idx]){
		res = gcd(res, abs(x - num[idx]));
		return;
	}
	mark[idx] = true;
	num[idx] = x;
	for(int i = 0; i < adj[idx].size(); i++)
		dfs(adj[idx][i], x + 1);
	for(int i = 0; i < rev[idx].size(); i++)
		dfs(rev[idx][i], x - 1);
}

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i, 1);
	cout << (res == 0 ? n : res) << endl;
	return 0;
}