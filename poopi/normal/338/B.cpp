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
#define Max 100010

int n, m, d;
int mx[Max][2];
bool ok[Max];
bool bad[Max];
vector <int> adj[Max];

void dfs(int idx, int par){
	mx[idx][0] = mx[idx][1] = (ok[idx] ? 0 : -Inf);
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v != par){
			dfs(v, idx);
			mx[idx][1] = max(mx[idx][1], mx[v][0] + 1);
			if(mx[idx][0] < mx[idx][1])
				swap(mx[idx][0], mx[idx][1]);
		}
	}
	if(mx[idx][0] > d)
		bad[idx] = true;
}

void check(int idx, int par, int oth){
	if(ok[idx] && oth < 0)
		oth = 0;
	if(oth > d)
		bad[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v != par){
			if(mx[v][0] + 1 == mx[idx][0])
				check(v, idx, max(oth + 1, mx[idx][1] + 1));
			else check(v, idx, max(oth + 1, mx[idx][0] + 1));
		}
	}
}

int main(){
	cin >> n >> m >> d;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a;
		ok[a - 1] = true;
	}
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	check(0, -1, -Inf);
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(!bad[i])
			cnt++;
	cout << cnt << endl;
	return 0;
}