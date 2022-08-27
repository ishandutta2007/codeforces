#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7, R = 5e5 + 7, M = 15, ic = 1e9;
int n, m, f[N][6], w[N], rc[R], arr[R], atot, dp[1 << M];

mt19937_64 orz(time(0) ^ clock());
int ns = 2e9 + 7;

void solve() {
	L(i, 1, atot) rc[i] = orz() % M;
	me(dp, 0x3f);
	L(i, 1, n) {
		int msk = 0;
		L(j, 1, m) msk |= 1 << rc[f[i][j]];
		dp[msk] = min(dp[msk], w[i]);
	}
	L(i, 0, M - 1) 
		L(j, 0, (1 << M) - 1) if(j >> i & 1) 
			dp[j] = min(dp[j], dp[j ^ (1 << i)]);
	int al = (1 << M) - 1;
	L(i, 0, (1 << (M - 1)) - 1) if(dp[i] <= ic && dp[al ^ i] <= ic) 
		ns = min(ns, dp[i] + dp[al ^ i]);
} 

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) {
		L(j, 1, m) cin >> f[i][j], arr[++atot] = f[i][j];
		cin >> w[i];
	} 
	sort(arr + 1, arr + atot + 1);
	L(i, 1, n) L(j, 1, m) 
		f[i][j] = lower_bound(arr + 1, arr + atot + 1, f[i][j]) - arr;
		
	int t = 40;
	while(t--) {
		solve();
	}
	
	if(ns > 2e9) {
		cout << -1 << '\n';
	} else cout << ns << '\n';
	return 0;
}