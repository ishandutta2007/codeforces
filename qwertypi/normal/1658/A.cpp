#include <bits/stdc++.h>

// ...
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	vector<int> a;
	for(int i = 0; i < n; i++){
		if(s[i] == '0') a.push_back(i);
	}
	int ans = 0;
	for(int i = 0; i < (int) a.size() - 1; i++){
		ans += max(0, 3 - a[i + 1] + a[i]);
	}
	cout << ans << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}