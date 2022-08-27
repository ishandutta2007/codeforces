#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 505, mod = 1e9 + 7;
int n, m, e[N][N], f[N][N], g[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) L(j, 1, n) cin >> e[i][j];
	L(i, 1, n) g[i][i] = f[i][i] = 1;
	L(len, 1, n) L(l, 1, n - len + 1) {
		int r = l + len - 1;
		L(k, l, r - 1) if(e[l][r]) (g[l][r] += (ll) f[l][k] * f[k + 1][r] % mod) %= mod;
		L(k, l + 1, r) (f[l][r] += (ll) g[l][k] * f[k][r] % mod) %= mod;	
	} 
	cout << f[1][n] << '\n';
	
	return 0;
}