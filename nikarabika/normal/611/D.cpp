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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 5000 + 100;
const LL Mod = 1000LL * 1000 * 1000 + 7;
LL dp[maxn][maxn], sum[maxn][maxn];
int cnt[maxn][maxn], a[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for(int i = n - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
			cnt[i][j] = (cnt[i + 1][j + 1] + 1) * (a[i] == a[j]);
	dp[n - 1][0] = 1;
	sum[n - 1][0] = 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i] == 0)
			continue;
		dp[i][n - i - 1] = 1;
		sum[i][n - i - 1] = 1;
		for(int j = n - i - 2; j >= 0; j--){
			int eqlen = cnt[i][i + j + 1];
			dp[i][j] = sum[i + j + 1][j + 1];
			if(eqlen <= j and a[i + eqlen] < a[i + j + eqlen + 1])
				dp[i][j] = (dp[i][j] + dp[i + j + 1][j]);
			sum[i][j] = (sum[i][j + 1] + dp[i][j]) % Mod;
		}
	}
	LL ans = 0;
	for(int i = 0; i < n; i++)
		ans = (ans + dp[0][i]) % Mod;
	cout << ans << endl;
	return 0;
}