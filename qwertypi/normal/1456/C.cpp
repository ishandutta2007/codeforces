#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int> pos, neg;

int dp[500001][3];

int slot[500001];
int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		if(v < 0){
			neg.push_back(v);
		}else{
			pos.push_back(v);
		}
	}
	
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	int score = 0, inc = 0;
	for(int i = (int) pos.size() - 1; i >= 0; i--){
		score += inc;
		inc += pos[i];
	}
	
	int m = neg.size();
	int res = 0;
	for(int i = 0; i < (int) neg.size(); i++){
		res += slot[i % (k + 1)] * neg[i];
		slot[i % (k + 1)]++;
		dp[i + 1][0] = res;
	}
	
	{
		int score = 0, inc = 0;
		for(int i = (int) neg.size() - 1; i >= 0; i--){
			score += inc;
			inc += neg[i];
			dp[(int) neg.size() - i][1] = score;
			dp[(int) neg.size() - i][2] = inc;
		}
	}
	
	int ans = -(1LL << 60);
	for(int i = 0; i <= (int) neg.size(); i++){
		int b = (i + k) / (k + 1) + m - i;
		// cout << score << ' ' << inc << ' ' << dp[i][0] << ' ' << dp[(int) neg.size() - i][1] << ' ' << dp[i][0] + dp[(int) neg.size() - i][1] + inc * b + score << endl;
		int tans = dp[i][0] + dp[(int) neg.size() - i][1] + dp[m - i][2] * ((i + k) / (k + 1)) + inc * b + score;
		ans = max(ans, tans);
	}
	cout << ans << endl;
}