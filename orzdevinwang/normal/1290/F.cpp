#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 5, M = 21, mod = 998244353;
int dp[M][M][M][M][2][2]; 
int h[M][M][M][M][2][2];
int n, m, x[N], y[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	L(i, 0, n - 1) cin >> x[i] >> y[i];
	dp[0][0][0][0][0][0] = 1;
	while (m > 0) {
		memset(h, 0, sizeof(h));
		L(a, 0, M - 1) L(b, 0, M - 1) L(c, 0, M - 1) L(d, 0, M - 1) L(o, 0, 1) L(z, 0, 1) if(dp[a][b][c][d][o][z]) {
			L(i, 0, (1 << n) - 1) {
				int va = a, vb = b, vc = c, vd = d;
				L(j, 0, n - 1) if(i >> j & 1) {
					if(x[j] > 0) va += x[j];
					else vb -= x[j];
					if(y[j] > 0) vc += y[j];
					else vd -= y[j];
				}
				if((va & 1) == (vb & 1) && (vc & 1) == (vd & 1)) {	
					int ho = o, hz = z;
					if((va & 1) > (m & 1)) ho = true;
					if((va & 1) < (m & 1)) ho = false;
					if((vc & 1) > (m & 1)) hz = true;
					if((vc & 1) < (m & 1)) hz = false;
					(h[va >> 1][vb >> 1][vc >> 1][vd >> 1][ho][hz] += dp[a][b][c][d][o][z]) %= mod;
				}
			}
		} 
		m >>= 1;
		swap (dp, h);
	} 
	cout << (dp[0][0][0][0][0][0] + mod - 1) % mod << '\n';
	return 0;
}