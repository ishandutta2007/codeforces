#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20);
int n, B, cB, h[15][15];
char str[99][99];
ll dp[1 << 14][14][1 << 6], ns[1 << 15], rev[1 << 15];
mt19937 orz(time(0) ^ clock());
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	B = (n + 1) / 2, cB = n - B;
	L(i, 0, n - 1) cin >> str[i];
	L(i, 0, n - 1) L(j, 0, n - 1) h[i][j] = str[i][j] - '0';
	L(i, 0, n - 1) dp[1 << i][i][0] = 1;
	for(int i = 1; i < 1 << n; ++i) {
		int x = __builtin_popcount (i);
		if(x < B) for(int k = 0; k < n; ++k) if(i >> k & 1) for(int j = 0; j < 1 << (x - 1); ++j) if(dp[i][k][j]) 
			for(int d = 0; d < n; ++d) if(!(i >> d & 1)) dp[i | (1 << d)][d][j | (h[k][d] << (x - 1))] += dp[i][k][j];
	}
	L(i, 0, (1 << (cB - 1)) - 1) 
		L(j, 0, cB - 2) rev[i] |= (i >> j & 1) << (cB - j - 2);
	for(int i = 0; i < (1 << n); ++i) if(__builtin_popcount(i) == B) {
		int S = ((1 << n) - 1) ^ i;
		for(int x = 0; x < n; ++x) if(i >> x & 1) for(int y = 0; y < n; ++y) if(S >> y & 1) 
			for(int m1 = 0; m1 < 1 << (B - 1); ++m1) if(dp[i][x][m1]) for(int m2 = 0; m2 < 1 << (cB - 1); ++m2) 
			if(dp[S][y][m2]) ns[m1 | (h[x][y] << (B - 1)) | (rev[m2] << B)] += dp[i][x][m1] * dp[S][y][m2];
	}
	L(i, 0, (1 << (n - 1)) - 1) 
		cout << ns[i] << " ";
	return 0;
}