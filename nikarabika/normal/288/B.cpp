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

const int maxn = 10;
const LL Mod = 1e9 + 7;
LL dp[maxn][maxn];
int n, K;

LL C(int n, int r){
	LL ret = 1;
	for(int i = 0; i < r; i++)
		ret = ret * (n - i) / (i + 1);
	return ret % Mod;
}

LL Pow(LL x, LL y){
	if(y == 1) return x;
	return (x * Pow(x, y - 1)) % Mod;
}

void calc(void){
	fill(dp[0], dp[0] + maxn, 1);
	for(int i = 1; i < K; i++)
		for(int j = 1; j <= K; j++)
			for(int k = 1; k <= i; k++)
				dp[i][j] = (dp[i][j] + dp[i - k][k] * C(i, k) * Pow(j, k)) % Mod;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> K;
	calc();
	LL ans = dp[K - 1][1];
	for(int i = 0; i < n - K; i++)
		ans = (ans * (n - K)) % Mod;
	cout << (ans * K) % Mod << endl;
	return 0;
}