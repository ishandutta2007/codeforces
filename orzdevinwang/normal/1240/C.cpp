#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7; 
int n, k;
ll dp[N][2];
vi e[N];
int ehd[N], ev[N], enx[N], ew[N], eid;
void eadd (int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
void dfs (int x, int fa) {
	ll sum = 0;
	vector < ll > S;
	for (int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) {
		dfs(ev[i], x);
		sum += dp[ev[i]][0];
		S.push_back(dp[ev[i]][1] - dp[ev[i]][0] + ew[i]);
	}
	dp[x][0] = dp[x][1] = sum;
	sort(S.begin(), S.end()), reverse(S.begin(), S.end());
//	if(x == 1) 
//		cout << sum << ' ' << S[0] << ' ' << S[1] << '\n';
	L(i, 0, min(k, sz(S)) - 1) dp[x][0] += max(S[i], 0LL);
	L(i, 0, min(k - 1, sz(S)) - 1) dp[x][1] += max(S[i], 0LL);
//	cout << x << " : " <<dp[x][0] << ' ' << dp[x][1] << '\n';
}
void Main () {
	cin >> n >> k;
	L(i, 1, n) ehd[i] = 0;
	eid = 0;
	L(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		eadd (u, v, w);
		eadd (v, u, w);
	}
	dfs (1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}