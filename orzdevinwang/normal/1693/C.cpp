#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7;
int n, m, dp[N], cnt[N];
vi e[N], re[N];
bool vis[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		cnt[u] += 1;
		e[u].emplace_back(v);
		re[v].emplace_back(u);
	}
	me(dp, 0x3f); 
	priority_queue < pair < int, int > > q;
	dp[n] = 0;
	q.push(make_pair(0, n));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(const int &v : re[u]) {
			dp[v] = min(dp[v], cnt[v] + dp[u]);
			cnt[v] -= 1;
			q.push(make_pair(-dp[v], v));
		}
	}
	cout << dp[1] << '\n';
	return 0;
}