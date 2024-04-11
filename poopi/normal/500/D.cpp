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

int n, q;
bool mark[100010];
int64 w[100010];
int64 cnt[100010];
vector <P> adj[100010];

int64 dfs(int idx){
	int64 ret = 1;
	mark[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++){
		int v = adj[idx][i].first;
		int ref = adj[idx][i].second;
		if(!mark[v]){
			int64 tmp = dfs(v);
			ret += tmp;
			cnt[ref] = tmp * (n - tmp);
		}
	}
	return ret;
}

int main(){
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b >> w[i];
		a--, b--;
		adj[a].push_back(P(b, i));
		adj[b].push_back(P(a, i));
	}
	dfs(0);

	int64 ans = 0;
	for(int i = 0; i < n - 1; i++)
		ans += cnt[i] * w[i];

	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		a--;
		ans -= cnt[a] * w[a];
		w[a] = b;
		ans += cnt[a] * w[a];
		cout << setprecision(8) << fixed << (double)ans * 6 / n / (n - 1) << endl;
	}
	return 0;
}