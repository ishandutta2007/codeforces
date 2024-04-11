#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 107;
int dp[N][N * N], n, w[N], cnt[N], ns;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> w[i], cnt[w[i]] += 1;
	dp[0][0] = 1;
	L(i, 1, 100) if(cnt[i]) {
		R(a, 100, 0) R(b, 10000, 0) if(dp[a][b]) 
			L(j, 1, cnt[i]) dp[a + j][b + i * j] += dp[a][b];
		R(a, 100, 0) R(b, 10000, 0) 
			dp[a][b] = min(dp[a][b], 2);
	}
//	cout << dp[2][8] << '\n';
	int ns = 0;
	L(i, 1, 100) if(cnt[i]) {
		L(j, 1, cnt[i]) 
			if(dp[j][j * i] == 1) 
				ns = max(ns, j);
	}
	int nt = 0;
	L(i, 1, n) nt += !!cnt[i];
	if(nt == 2) return cout << n << '\n', 0;
	cout << ns << '\n';
	return 0; 
}