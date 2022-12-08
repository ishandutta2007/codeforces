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

int n, m, fb;
bool mat[110][110];
bool mark[110];

int dfs1(int v){
	int cnt = 1;
	mark[v] = true;
	for(int i = 0; i < n; i++)
		if(mat[v][i] && !mark[i])
			cnt += dfs1(i);
	return cnt;
}

int dfs2(int v, int par){
	int ret = -1;
	mark[v] = true;
	for(int i = 0; i < n; i++){
		if(mat[v][i]){
			if(!mark[i]){
				int t = dfs2(i, v);
				if(t != -1){
					mat[v][i] = mat[i][v] = false;
					if(t != v)
						ret = t;
				}
			}
			else if(i != par){
				ret = i;
				mat[i][v] = mat[v][i] = false;
			}
		}
	}
	return ret;
}

int main(){
	while(cin >> n >> m){
		int a, b;
		memset(mat, false, sizeof mat);
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			a--, b--;
			mat[a][b] = mat[b][a] = true;
		}
		if(n != m){
			cout << "NO" << endl;
			continue;
		}
		memset(mark, false, sizeof mark);
		if(dfs1(0) != n){
			cout << "NO" << endl;
			continue;
		}
		memset(mark, false, sizeof mark);
		dfs2(0, -1);
		int cnt = 0;
		memset(mark, false, sizeof mark);
		for(int i = 0; i < n; i++){
			if(!mark[i]){
				dfs1(i);
				cnt++;
			}
		}
		cout << (cnt >= 3 ? "FHTAGN!" : "NO") << endl;
	}
	return 0;
}