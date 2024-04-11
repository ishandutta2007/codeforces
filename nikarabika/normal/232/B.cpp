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

const int maxn = 100 + 10,
	  maxk = 100 * 100 + 10;
const LL Mod = 1000 * 1000 * 1000 + 7;
LL dp[maxn][maxk],
   P[maxn][2],
   c[maxn];
LL n, m, cnt;

LL Pow(LL x, LL y){
	LL an = x % Mod, ret = 1;
	while(y){
		if(y & 1) ret = (ret * an) % Mod;
		an = (an * an) % Mod;
		y >>= 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> cnt;
	c[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = i; j; j--){
			c[j] += c[j - 1];
			if(c[j] >= Mod) c[j] -= Mod;
		}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 2; j++)
			P[i][j] = Pow(c[i], m/n + j);
	LL md = m % n;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i * n; j++)
			for(int k = 0; k <= n and k <= j; k++)
				dp[i][j] = (dp[i][j] + P[k][i <= md] * dp[i - 1][j - k]) % Mod;
	cout << dp[n][cnt] << '\n';
	return 0;
}