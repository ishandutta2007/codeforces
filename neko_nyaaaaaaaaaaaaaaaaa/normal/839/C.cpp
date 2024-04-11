#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxn = 2e5 + 17, maxv = 1e6 + 17, mod = 1e9 + 7;

int n;
vector<int> g[maxn];
ld dfs(int v = 0, int p = -1){
	ld sum = 0;
	for(auto u : g[v])
		if(u != p)
			sum += dfs(u, v) + 1;
	return sum ? sum / (g[v].size() - (p != -1)) : 0;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int v, u, i = 1; i < n; i++){
		cin >> v >> u, v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	cout << fixed << setprecision(7) << dfs() << '\n';
	return 0;
}