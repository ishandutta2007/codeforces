#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e2 + 85;
int a[maxn][maxn], dp[maxn][maxn];
int Max[maxn];
int n, m, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++){
		for(int j = m; j > 0; j--){
			dp[i][j] = (a[i][j] == 1) * (dp[i][j + 1] + 1);
			Max[i] = max(Max[i], dp[i][j]);
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		a[x][y] = 1 - a[x][y];
		Max[x] = 0;
		for(int j = m; j > 0; j--){
			dp[x][j] = (a[x][j] == 1) * (dp[x][j + 1] + 1);
			Max[x] = max(Max[x], dp[x][j]);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans = max(ans, Max[i]);
		cout << ans << endl;
	}
	return 0;
}