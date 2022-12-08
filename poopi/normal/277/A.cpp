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

int n, m;
bool mark[210];
bool mat[210][210];

void dfs(int idx){
	mark[idx] = true;
	for(int i = 0; i < n + m; i++)
		if(!mark[i] && mat[idx][i])
			dfs(i);
}

int main(){
	cin >> n >> m;
	int a, b, k;
	bool fl = false;
	for(int i = 0; i < n; i++){
		cin >> k;
		if(k > 0)
			fl = true;
		for(int j = 0; j < k; j++){
			cin >> b;
			a = i, b--;
			mat[a][b + n] = mat[b + n][a] = true;
		}
	}
	if(!fl){
		cout << n << endl;
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			cnt++;
			dfs(i);
		}
	}
	cout << cnt - 1 << endl;
	return 0;
}