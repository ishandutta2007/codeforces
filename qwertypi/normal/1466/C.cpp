#include <bits/stdc++.h>

#define int long long
using namespace std;

int dp[100001][26];

void sub(){
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(i >= 1 && s[i] == s[i - 1] && s[i - 1] != 0){
			s[i] = 0;
			ans++;
		}
		if(i >= 2 && s[i] == s[i - 2] && s[i - 2] != 0){
			s[i] = 0;
			ans++;
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}