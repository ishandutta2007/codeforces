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

const int maxn = 1000 + 85 - 69,
	  maxm = 10 + 1;
int dp[maxn][maxm],
	a[maxm],
	b[maxm],
	c[maxm],
	d[maxm];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> c[0] >> d[0];
	for(int i = 1; i <= m; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i = 1; i <= n; i++){
		dp[i][0] = (i / c[0]) * d[0];
		for(int j = 1; j <= m; j++)
			for(int k = 0; k <= i / c[j] and k <= a[j] / b[j]; k++)
				smax(dp[i][j], dp[i - c[j] * k][j - 1] + d[j] * k);
	}
	cout << dp[n][m] << endl;
	return 0;
}