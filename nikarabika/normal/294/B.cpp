#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 17 * 5 - 23 * 3 - 15;
int t[maxn], w[maxn], sow;
int dp[maxn << 1];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> w[i];
		sow += w[i];
	}
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 200; j >= 0; j--)
			if(j - t[i] >= 0 and dp[j - t[i]] != -1)
				dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
	for(int j = 0; j <= 200; j++){
		if(dp[j] != -1){
			if(sow - dp[j] <= j){
				cout << j << endl;
				return 0;
			}
		}
	}
	return 0;
}