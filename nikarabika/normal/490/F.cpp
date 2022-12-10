#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define smax(x, y) (x) = max((x), (y))

const int maxn = 6000 + 10;
vector<int> adj[maxn];
int vec[maxn][maxn], sz[maxn], pos[maxn];
int r[maxn];
int n, ans;

void insert(int v){
	int lo = -1, hi = maxn;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(vec[mid][sz[mid] - 1] < r[v])
			lo = mid;
		else
			hi = mid;
	}
	smax(ans, hi + 1);
	vec[hi][sz[hi]++] = r[v];
	pos[v] = hi;
	return;
}

void remove(int v){
	sz[pos[v]]--;
	return;
}

void dfs(int v, int p = -1){
	insert(v);
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v);
	remove(v);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> r[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < maxn; i++)
		vec[i][sz[i]++] = 10000000;
	for(int i = 1; i <= n; i++)
		dfs(i);
	cout << ans << endl;
	return 0;
}