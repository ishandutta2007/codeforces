#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt[26];

int dp[26][26];
int32_t main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		int id = s[i] - 'a';
		for(int j = 0; j < 26; j++){
			dp[j][id] += cnt[j];
		}
		
		cnt[id]++;
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	for(int i = 0; i < 26; i++){
		ans = max(ans, cnt[i]);
	}
	cout << ans << endl;
}