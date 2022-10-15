#include <bits/stdc++.h>
using namespace std;
 
const int N = 2020, MOD = 1e9 + 7;
 
int n, d, u, v, i, a[N];
long long ans;
vector<int> edges[N];
 
long long solve(int root, int cur, int par = -1) {
	long long res = 1;
 
	for (int v : edges[cur]) {
		if (v == par)
			continue;
		if (a[v] < a[root] || a[v] - a[root] > d)
			continue;
		if (a[v] == a[root] && v <= root)
			continue;
 
		res = (res * (solve(root, v, cur) + 1)) % MOD;
	}
 
	return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> d >> n;
	for (i = 1; i <= n; ++i) {
	    cin>>a[i];
	}
	for (i = 2; i <= n; ++i) {
	    cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for (i = 1; i <= n; ++i) {
		ans = (ans + solve(i, i)) % MOD;
	}
	cout << ans;
}