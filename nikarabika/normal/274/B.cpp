#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smax(x, y) (x) = max((x), (y))
#define PB push_back
#define dec DEC
#define inc INC

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn];
LL inc[maxn], dec[maxn], a[maxn];
int n;

void dfs(int v, int p = -1){
	for(auto u : adj[v]) if(u != p){
		dfs(u, v);
		smax(inc[v], inc[u]);
		smax(dec[v], dec[u]);
	}
	int val = inc[v] - dec[v];
	if(val < a[v])
		inc[v] += a[v] - val;
	else
		dec[v] += val - a[v];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	cout << inc[1] + dec[1] << endl;
	return 0;
}