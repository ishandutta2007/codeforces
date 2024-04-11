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

int n, m;
vector <int> adj[200010];

P dfs(int idx, int h){
	if(adj[idx].empty()){
		m++;
		return P(1, 1);
	}

	P ret;
	if(h % 2)
		ret = P(0, Inf);
	else ret = P(Inf, 0);

	for(int i = 0; i < adj[idx].size(); i++){
		P tmp = dfs(adj[idx][i], h + 1);
		if(h % 2){
			ret.first += tmp.first;
			ret.second = min(ret.second, tmp.second);
		}
		else{
			ret.first = min(ret.first, tmp.first);
			ret.second += tmp.second;
		}
	}
	return ret;
}

int main(){
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
	}
	P res = dfs(0, 0);
	cout << m - res.first + 1 << ' ' << res.second << endl;
	return 0;
}