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
#define Inf 10000000LL * 10000000LL
#define Mod 1000000007LL

int n;
int64 sum;
int64 val[100010];
int64 d[100010];
vector <int> adj[100010];

int64 gcd(int64 a, int64 b){
	return (b == 0 ? a : gcd(b, a % b));
}

int64 lcm(int64 a, int64 b){
	int64 na = a / gcd(a, b);
	double t1 = log10((double)na);
	double t2 = log10((double)b);
	if(t1 + t2 > 14)
		return Inf;
	return na * b;
}

void dfs(int idx, int par){
	if(adj[idx].size() == 1){
		d[idx] = 1;
		return;
	}
	for(int i = 0; i < adj[idx].size(); i++)
		if(adj[idx][i] != par)
			dfs(adj[idx][i], idx);
	d[idx] = 1;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v != par)
			d[idx] = lcm(d[idx], d[v]);
	}
	int64 tmp = -1;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v == par) continue;
		if(tmp == -1 || tmp > val[v] / d[idx])
			tmp = val[v] / d[idx];
	}
	d[idx] *= adj[idx].size() - 1;
	val[idx] = tmp * d[idx];
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> val[i];
		sum += val[i];
	}
	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	adj[0].push_back(-1);
	dfs(0, -1);
	cout << sum - val[0] << endl;
	return 0;
}