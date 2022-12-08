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
#define pll pair<int64, int64>

int n;
int64 res;
vector <int> adj[80010];

int dfs(int idx, int par){
	int cnt = 1;
	int64 arr[5] = {};
	arr[0] = 1;
	for(int i = 0; i < adj[idx].size(); i++){
		if(adj[idx][i] != par){
			int tmp = dfs(adj[idx][i], idx);
			cnt += tmp;
			for(int j = 4; j > 0; j--)
				arr[j] += arr[j - 1] * tmp;
		}
	}
	for(int i = 4; i > 0; i--)
		arr[i] += arr[i - 1] * (n - cnt);
	res -= arr[4] + arr[3];
	return cnt;
}

int main(){
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	res = n;
	for(int i = 1; i <= 3; i++)
		res = (res * (n - i)) / (i + 1);
	dfs(0, -1);
	cout << 2 * res << endl;
	return 0;
}