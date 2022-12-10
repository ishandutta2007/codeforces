//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2000 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7;
LL dp[maxn][maxn];
int n, m;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m
		>> s;
	if(n & 1){
		cout << 0 << endl;
		return 0;
	}
	int len = n - m;
	int sop = 0, scl = 0, maxdif = 0;
	int sopp = 0, sclp = 0, maxdifp = 0;
	for(int i = 0; i < sz(s); i++){
		if(s[i] == '(') sop++;
		else scl++;
		smax(maxdif, scl - sop);
	}
	for(int i = sz(s) - 1; i >= 0; i--){
		if(s[i] == ')') sopp++;
		else sclp++;
		smax(maxdifp, sclp - sopp);
	}
	dp[0][0] = 1;
	for(int i = 1; i <= len; i++)
		for(int j = 0; j <= len; j++){
			if(j - (i - 1 - j) >= 1)
				dp[i][j] = dp[i - 1][j];
			if(j){
				dp[i][j] += dp[i - 1][j - 1];
				if(dp[i][j] >= Mod)
					dp[i][j] -= Mod;
			}
		}
	//cout << maxdif << ' ' << maxdifp << endl;
	LL ans = 0;
	for(int i = 0; i <= len; i++){
		for(int j = (maxdif + i + 1) / 2; j <= i; j++){
			int ii = len - i;
			int jj = n / 2 - (j + sop);
			int jjp = ii - jj;
			if(jj >= 0 and jjp >= 0 and jjp >= (maxdifp + ii + 1) / 2){
				ans += dp[i][j] * dp[ii][jjp];
				//cout << i << ' ' << j << ' ' << dp[i][j] * dp[ii][jjp] << endl;
				ans %= Mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}