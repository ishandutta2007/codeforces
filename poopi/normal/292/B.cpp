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
#define PLL pair<int64, int64>

int n, m;
bool mark[100010];
vector <int> adj[100010];

int dfs(int idx){
	int cnt = 1;
	for(int i = 0; i < adj[idx].size(); i++)
		if(!mark[adj[idx][i]])
			cnt += dfs(adj[idx][i]);
	return cnt;
}

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int one = 0, two = 0;
	for(int i = 0; i < n; i++){
		if(adj[i].size() == 1) one++;
		if(adj[i].size() == 2) two++;
	}
	if(two == n)
		cout << "ring topology" << endl;
	else if(two == n - 2 && one == 2)
		cout << "bus topology" << endl;
	else if(one == n - 1)
		cout << "star topology" << endl;
	else cout << "unknown topology" << endl;
	return 0;
}