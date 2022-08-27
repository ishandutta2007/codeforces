#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2005, mod = 1e9 + 7;
int n, m, a[N];
int dp1[N][N], dp2[N][N]; // dp1 : right; dp2 : down  
int cf1[N][N], cf2[N][N];
int cnt1[N][N], cnt2[N][N];
char s[N][N];
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if(n == 1 && m == 1) return cout << 1 << '\n', 0;
    L(i, 1, n) cin >> (s[i] + 1);
    L(i, 1, n) L(j, 1, m) 
		cnt1[i][j] = cnt2[i][j] = s[i][j] == 'R';
	
	L(i, 1, n) R(j, m - 1, 1) cnt1[i][j] += cnt1[i][j + 1];
	L(j, 1, m) R(i, n - 1, 1) cnt2[i][j] += cnt2[i + 1][j];
		
    dp1[1][1] = dp2[1][1] = 1;
	L(i, 1, n) {
    	L(j, 1, m) {
    		(cf1[i][j] += cf1[i - 1][j]) %= mod;
    		(cf2[i][j] += cf2[i][j - 1]) %= mod;
    		if(i != 1 || j != 1) dp1[i][j] = cf1[i][j], dp2[i][j] = cf2[i][j];
    		
    		int ct1 = cnt1[i][j + 1], ct2 = cnt2[i + 1][j]; 
    		(cf2[i][j + 1] += dp1[i][j]) %= mod;
    		(cf2[i][m - ct1 + 1] += mod - dp1[i][j]) %= mod;
			 
			(cf1[i + 1][j] += dp2[i][j]) %= mod;
			(cf1[n - ct2 + 1][j] += mod - dp2[i][j]) %= mod;
//			L(k, j + 1, m - ct1) 
//    			(dp2[i][k] += dp1[i][j]) %= mod;
//    		L(k, i + 1, n - ct2) 
//    			(dp1[k][j] += dp2[i][j]) %= mod;
		}
	}
    cout << (dp1[n][m] + dp2[n][m]) % mod << "\n";
	return 0;
}