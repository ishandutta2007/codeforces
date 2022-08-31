#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7, mod = 998244353;
int n;
vi e[N];
int dp[N][2], pr[N], s[2];
void dfs (int x, int fa) {
	dp[x][1] = 1;
	for (const int &v : e[x]) if(v != fa) {
		dfs (v, x);
		
		s[0] = s[1] = 0;
		(s[0] += (ll) dp[x][1] * dp[v][1] % mod) %= mod; 
		
		(s[0] += (ll) dp[x][0] * dp[v][0] * 2 % mod) %= mod;
		(s[0] += (ll) dp[x][0] * pr[v] % mod) %= mod;
		
		(s[1] += (ll) dp[x][1] * dp[v][0] * 2 % mod) %= mod;
		(s[1] += (ll) dp[x][1] * pr[v] % mod) %= mod;
		
		dp[x][0] = s[0], dp[x][1] = s[1]; 
	}
	
	pr[x] = 1;
	for (const int &v : e[x]) if(v != fa) pr[x] = (ll) pr[x] * (dp[v][0] + pr[v]) % mod;
	
//	cout << x << " : " << dp[x][0] << ' ' << dp[x][1] << ' ' << pr[x] << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1, 0);
	cout << (dp[1][0] + pr[1]) % mod << '\n';
	return 0; 
}