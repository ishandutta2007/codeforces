#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define uint unsigned int


    
using namespace std;

const int MOD = 998244353;
const int MAXN = 2005;

int dp[MAXN + 1][2 * MAXN + 2];
  
int main() {
#ifdef HOME
    ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
	int i, j, n, k;
    ios::sync_with_stdio(false);
   	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	
	vector <int> h(n);
	for(i = 0; i < n; i++) {
		cin >> h[i];
	}
	
	if(h[0] == h[1 % n]) {
		dp[0][MAXN] = k;
	}
	else {
		dp[0][1 + MAXN] = 1;
		dp[0][-1 + MAXN] = 1;
		dp[0][MAXN] = k - 2;
	}
	
	for(i = 1; i < n; i++) {
		if(h[i] == h[(i + 1) % n]) {
			for(j = 0; j <= 2 * MAXN; j++) {
				dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j] * k) % MOD;
			}
		}
		else {
			for(j = 0; j <= 2 * MAXN; j++) {
				dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j] * (k - 2)) % MOD;
				if(j > 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
				}
				if(j < 2 * MAXN) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
				}
			}
		}
	}
	
	int ans = 0;
	for(i = 0; i < MAXN; i++) {
		ans = (ans + dp[n - 1][i]) % MOD;
	}
	
	cout << ans;
	
	return 0;
}