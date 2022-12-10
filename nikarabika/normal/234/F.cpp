#include <bits/stdc++.h>

using namespace std;

#define cin fin
#define cout fout

const int maxn = 2e2 + 10, maxa = 4e4 + 10;
int dp[maxn][maxa], pd[maxn][maxa], h[maxn], s[maxn];
int a, b, n;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxa; j++)
			dp[i][j] = pd[i][j] = -1;
	cin >> n >> a >> b;
	if(a > b)
		swap(a, b);
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = n; i > 0; i--)
		s[i] = s[i + 1] + h[i];
	dp[n][h[n]] = (a >= h[n]) ? 0 : -1;
	pd[n][0] = (b >= h[n]) ? 0 : -1;
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j <= a; j++){
			//DP
			if(j >= h[i]){
				dp[i][j] = dp[i + 1][j - h[i]];
				if(s[i] - j <= b and s[i] - j >= 0 and pd[i + 1][j - h[i]] != -1)
					dp[i][j] = (dp[i][j] == -1) ? pd[i + 1][j - h[i]] + min(h[i], h[i + 1]) : min(pd[i + 1][j - h[i]] + min(h[i], h[i + 1]), dp[i][j]);
			}
			//PD
			if(s[i] - j <= b and s[i] - j >= h[i]){
				pd[i][j] = pd[i + 1][j];
				if(dp[i + 1][j] != -1)
					pd[i][j] = (pd[i][j] == -1) ? dp[i + 1][j] + min(h[i], h[i + 1]) : min(pd[i][j], dp[i + 1][j] + min(h[i], h[i + 1]));
			}
		}
	}
	int dp1 = 1e6, pd1 = 1e6;
	for(int i = 0; i <= a; i++){
		if(dp[1][i] != -1 and dp[1][i] < dp1)
			dp1 = dp[1][i];
		if(pd[1][i] != -1 and pd[1][i] < pd1)
			pd1 = pd[1][i];
	}
	if(dp1 == 1e6 and pd1 == 1e6)
		cout << -1 << endl;
	else if(dp1 == 1e6)
		cout << pd1 << endl;
	else if(pd1 == 1e6)
		cout << dp1 << endl;
	else
		cout << min(dp1, pd1) << endl;
	return 0;
}