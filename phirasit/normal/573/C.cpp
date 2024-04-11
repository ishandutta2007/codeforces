#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> adj[N];
int n;

int dfs(int u, int p) {
	int cnt[6];
	for(int i = 0;i < 6;i++) cnt[i] = 0;
	for(int v : adj[u]) {
		if(v == p) continue;
		int r = dfs(v, u);
		if(r == -1) return -1;
		cnt[r]++;
	}
	if(cnt[5] > 0) return -1;
	if(cnt[4] > 1) return -1;
	if(cnt[4] == 1) {
		if(cnt[3] > 0 or cnt[2] > 0 or cnt[1] > 0) return -1;
		if(cnt[0] > 1) return -1;
		if(cnt[0] == 1) return 5;
		return 4;
	}
	if(cnt[3] > 1) return -1;
	if(cnt[3] == 1) {
		if(cnt[2] > 0) return -1;
		return 4;
	} 
	if(cnt[2] > 2) return -1;
	if(cnt[2] == 2) return 3;
	if(cnt[2] == 1) return 2;
	if(cnt[1] > 0) return 2;
	if(cnt[0] > 2) return 2;
	if(cnt[0] == 2) return 1;
	if(cnt[0] == 1) return 0;
	return 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 0;i < n-1;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int r = dfs(1, -1);
	printf("%s\n", r != -1 ? "Yes" : "No");
	return 0;
}
/*
8
1 2
1 3
1 6
6 4
6 7
6 5
7 8
13
1 2
1 3
1 4
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13
*/