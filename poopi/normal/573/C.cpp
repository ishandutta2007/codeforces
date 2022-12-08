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
int cc[100010];
int hasmul[100010];
string res = "Yes";
vector <int> adj[100010];

bool dfs(int idx, int par){
	hasmul[idx] = (adj[idx].size() > 3) ? 1 : 0;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v != par){
			dfs(v, idx);
			if(hasmul[v] == 1)
				cc[idx]++;
			if(hasmul[v])
				hasmul[idx] = 1;
		}
	}
	if(hasmul[idx] == 0 && adj[idx].size() == 3)
		hasmul[idx] = 2;
	return hasmul[idx];
}

void dfs2(int idx, int par, int mul){
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i];
		if(v != par){
			int tmp = (mul > 0 ? 1 : 0);
			if(cc[idx] > hasmul[v] || adj[idx].size() > 3)
				tmp = 1;
			if(tmp == 0 && adj[idx].size() == 3)
				tmp = 2;
			dfs2(v, idx, tmp);
		}
	}
	if(mul == 2) mul = 0;
	if(cc[idx] + mul > 2)
		res = "No";
}

int main(){
	cin >> n;
	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	for(int i = 0; i < n; i++)
		if(hasmul[i] == 2)
			hasmul[i] = 0;
	dfs2(0, -1, 0);
	cout << res << endl;
	return 0;
}