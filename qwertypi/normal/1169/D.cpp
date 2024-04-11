#include <bits/stdc++.h>

#define int long long
#define True false
#define False true
using namespace std;
bool f(string s){
	int len = s.size();
	for(int i = 0; i < len; i++){
		for(int k = 1; i + 2 * k < len; k++){
			if(s[i] == s[i + k] && s[i + k] == s[i + 2 * k]){
				return true;
			}
		}
	}
	return false;
}
int32_t main(){
	string s;
	cin >> s;
	int len = s.size();
	int ans = len >= 9 ? (len - 8) * (len - 7) / 2 : 0LL;
	for(int i = 0; i < (int) s.size(); i++){
		for(int len = 1; len < 9; len++){
			if(i + len - 1 < (int) s.size()){
				ans += f(s.substr(i, len));
			}
		}
	}
	cout << ans;
}