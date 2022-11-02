#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[402][402];
int Next[402][26];
int _next[26];
void sub(){
	string s, t;
	cin >> s >> t;
	fill(_next, _next + 26, (1 << 30));
	for(int i = s.size() - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			Next[i + 1][j] = _next[j];
		}
		_next[s[i] - 'a'] = i + 1;
	}
	for(int i = 0; i < 26; i++){
		Next[0][i] = _next[i];
	}
	bool OK = false;
	for(int cut = 0; cut < t.size(); cut++){
		int x = cut, y = t.size() - cut;
		for(int i = 0; i <= x; i++){
			for(int j = 0; j <= y; j++){
				dp[i][j] = ((i == 0 && j == 0) ? 0 : (1 << 30));
			}
		}
		for(int i = 0; i <= x; i++){
			for(int j = 0; j <= y; j++){
				if(i != 0){
					if(dp[i - 1][j] == (1 << 30)){
						continue;
					}
					int d = Next[dp[i - 1][j]][t[i - 1] - 'a'];
					dp[i][j] = min(dp[i][j], d);
				}
				if(j != 0){
					if(dp[i][j - 1] == (1 << 30)){
						continue;
					}
					int d = Next[dp[i][j - 1]][t[cut + j - 1] - 'a'];
					dp[i][j] = min(dp[i][j], d);
				}
			}
		}
		if(dp[x][y] != (1 << 30)){
			OK = true;
		}
		Ne:;
	}
	cout << (OK ? "YES" : "NO") << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}