#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const int maxn = 110, maxm = 1010;
LD dp[maxn][maxn * maxm];
int a[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(16);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n == 1){
		cout << fixed << LD(a[1]) << endl;
		return 0;
	}
	if(m == 1){
		cout << fixed << LD(1) << endl;
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		LD sum = 0;
		for(int j = 1; j <= m * n; j++){
			sum += dp[i - 1][j - 1];
			if(j > m)
				sum -= dp[i - 1][j - m - 1];
			if(j >= a[i])
				dp[i][j] = (sum - dp[i - 1][j - a[i]]) / LD(m - 1);
			else
				dp[i][j] = sum / LD(m - 1);
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += a[i];
	LD ans = 0;
	for(int j = 1; j < sum; j++)
		ans += dp[n][j];
	cout << fixed << ans * LD(m - 1) + LD(1.0) << endl;
	return 0;
}