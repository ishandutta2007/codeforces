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

const int maxn = 1000;
int dp[3][maxn],
	a[maxn],
	n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	memset(dp, 63, sizeof dp);
	dp[0][n] = 0;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 3; j++)
			smin(dp[0][i], 1 + dp[j][i + 1]);
		if(a[i] & 1)
			smin(dp[1][i], min(dp[0][i + 1], dp[2][i + 1]));
		if(a[i] & 2)
			smin(dp[2][i], min(dp[0][i + 1], dp[1][i + 1]));
	}
	cout << min(dp[0][0], min(dp[1][0], dp[2][0])) << '\n';
	return 0;
}