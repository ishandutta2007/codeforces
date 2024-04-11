#include <bits/stdc++.h>

#define int long long
using namespace std;

void sub(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	cout << s << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}