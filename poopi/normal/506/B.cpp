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

int n, m, ptr;
bool mark[100010];
bool bad[100010];
int ord[100010];
vector <int> dir[100010];
vector <int> rev[100010];
vector <int> adj[100010];

bool dfs(int idx){
	bool ret = bad[idx];
	mark[idx] = true;
	for(int i = 0; i < adj[idx].size(); i++)
		if(!mark[adj[idx][i]])
			ret |= dfs(adj[idx][i]);
	return ret;
}

void setOrd(int idx){
	mark[idx] = true;
	for(int i = 0; i < dir[idx].size(); i++)
		if(!mark[dir[idx][i]])
			setOrd(dir[idx][i]);
	ord[--ptr] = idx;
}

int ccf(int idx){
	int cnt = 1;
	mark[idx] = true;
	for(int i = 0; i < rev[idx].size(); i++)
		if(!mark[rev[idx][i]])
			cnt += ccf(rev[idx][i]);
	return cnt;
}

int main(){
	cin >> n >> m;
	ptr = n;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		dir[a].push_back(b);
		rev[b].push_back(a);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int res = n;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			setOrd(i);

	memset(mark, false, sizeof mark);
	for(int i = 0; i < n; i++){
		if(!mark[ord[i]]){
			int tmp = ccf(ord[i]);
			if(tmp > 1)
				bad[ord[i]] = true;
		}
	}

	memset(mark, false, sizeof mark);
	for(int i = 0; i < n; i++)
		if(!mark[i] && !dfs(i))
			res--;
	cout << res << endl;
	return 0;
}