#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int idx = 0;
	for(int i = 0; i < (int) m - 1; i++){
		if(s[i] != t[i]){
			cout << "NO" << endl;
			return; 
		}
	}
	for(int i = m - 1; i < n; i++){
		if(s[i] == t[m - 1]){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}