#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, l[N], r[N];
ll mx1[N], mx2[N];
vi e[N];
void dfs(int x, int fa) {
	mx1[x] = mx2[x] = 0;
	for(int v : e[x]) if(v != fa) {
		dfs(v, x);
		mx1[x] += max(abs(l[v] - l[x]) + mx1[v], abs(r[v] - l[x]) + mx2[v]);
		mx2[x] += max(abs(l[v] - r[x]) + mx1[v], abs(r[v] - r[x]) + mx2[v]);
	}
} 
void Main() {
	cin >> n;
	L(i, 1, n) e[i].clear();
	L(i, 1, n) cin >> l[i] >> r[i];
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	cout << max(mx1[1], mx2[1]) << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}