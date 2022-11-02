#include <bits/stdc++.h>
 
using namespace std;
 
bool dp[1000][500];
void solve(){
	string s, t;
	cin >> s >> t;
	bool ok = false;
	for(int i = 0; i < s.size(); i++){
		for(int j = i; j < s.size(); j++){
			for(int k = 0; k <= j; k++){
			    if(j - i + 1 + j - 1 - k + 1 != t.size()) continue;
				string res;
				for(int x = i; x <= j; x++) res.push_back(s[x]);
				for(int x = j - 1; x >= k; x--) res.push_back(s[x]);
				ok |= res == t;
			}
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}