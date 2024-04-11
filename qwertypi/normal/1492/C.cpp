#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int dp[200001][2];
int32_t main(){
	int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s >> t;
	 
	{
		int l = 0, r = 0;
		while(r < m){
			if(s[l] == t[r]){
				dp[r][0] = l;
				l++, r++;
			}else{
				l++;
			}
		}
	}
 
	{
		int l = n - 1, r = m - 1;
		while(r >= 0){
			if(s[l] == t[r]){
				dp[r][1] = l;
				l--, r--;
			}else{
				l--;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < m - 1; i++){
		ans = max(ans, dp[i + 1][1] - dp[i][0]);
	}
	cout << ans << endl;
}