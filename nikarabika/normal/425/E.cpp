//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 500 + 85 - 69,
	  maxnn = maxn * maxn;
const LL Mod = 1e9 + 7;
LL dp[maxn][maxn];
LL P[maxnn];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < maxnn; i++)
		P[i] = (P[i - 1] * 2) % Mod;
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < j; k++){
				dp[i][j] += (((dp[i - 1][k] * (P[j - k] - 1)) % Mod) * P[(j - k) * (n - j)]) % Mod;
				if(dp[i][j] >= Mod) dp[i][j] -= Mod;
			}
		}
	}
	LL ans = 0;
	for(int i = 0; i <= n; i++){
		ans += dp[k][i];
		if(ans >= Mod) ans -= Mod;
	}
	cout << ans << '\n';
	return 0;
}