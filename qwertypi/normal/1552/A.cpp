#include <bits/stdc++.h>

using namespace std;

void sub(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t(s.begin(), s.end());
	sort(t.begin(), t.end());
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]) cnt++;
	}
	cout << cnt << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--) sub();
}