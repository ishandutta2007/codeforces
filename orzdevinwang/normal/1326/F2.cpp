#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 19, M = 1e4; 
int n, m, h[N][N];
ll dp[1 << N][N], cc[N][1 << N], sav[N][1 << N], now[1 << N], ns[M], cw[1 << N];
string S[N];
int ch[M][N], bu[1 << N], tot;
void Dfs (int id, int sum, int Mx) {
	if(sum == 0) {
		L(i, 0, (1 << n) - 1) ns[id] += bu[i] * now[i];
		return ;
	}
	R(i, min(Mx, sum), 1) {
		ch[id][i] = ++tot;
		L(j, 0, (1 << n) - 1) sav[sum][j] = now[j], now[j] *= cc[i][j];
		Dfs (ch[id][i], sum - i, i);
		L(j, 0, (1 << n) - 1) now[j] = sav[sum][j];
	} 
	
}
ll calc (int S) {
	int l = -1, now = 1; 
	vi h;
	L(i, 0, n - 1) if(!(S >> i & 1)) h.push_back(i - l), l = i;
	sort(h.begin(), h.end());
	R(i, sz(h) - 1, 0) now = ch[now][h[i]];
	return ns[now];
}
void fwt (ll *S, int n) {
	for(int i = 2; i <= n; i <<= 1) 
		for(int j = 0, l = i >> 1; j < n; j += i) 
			for(int k = j; k < j + l; k++) 
				S[k + l] += S[k];
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 0, (1 << n) - 1) bu[i] = bu[i >> 1] ^ (i & 1);
	L(i, 0, (1 << n) - 1) bu[i] = ((n & 1) ^ bu[i]) == 1 ? -1 : 1;
	L(i, 0, n - 1) cin >> S[i];
	L(i, 0, n - 1) L(j, 0, n - 1) h[i][j] = S[i][j] - '0';
	L(i, 0, n - 1) dp[1 << i][i] = 1;
	L(i, 0, (1 << n) - 1) L(j, 0, n - 1) if(dp[i][j]) {
		cc[__builtin_popcount(i)][i] += dp[i][j]; 
		L(k, 0, n - 1) if(!(i >> k & 1) && h[j][k]) dp[i ^ (1 << k)][k] += dp[i][j];
	} 
	L(i, 0, n) fwt(cc[i], 1 << n);
	L(i, 0, (1 << n) - 1) now[i] = 1;
	tot = 1, Dfs (1, n, n);
	L(i, 0, (1 << (n - 1)) - 1) 
		cw[i] = calc (i);
	for(int i = 2; i <= (1 << (n - 1)); i <<= 1) 
		for(int j = 0, l = i >> 1; j < (1 << (n - 1)); j += i) 
			for(int k = j; k < j + l; k++) 
				cw[k] -= cw[k + l];
	L(i, 0, (1 << (n - 1)) - 1) 
		cout << cw[i] << ' ';
	cout << '\n';
	return 0;
}