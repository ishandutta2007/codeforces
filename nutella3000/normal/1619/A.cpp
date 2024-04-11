#include<bits/stdc++.h>
using namespace std;

signed main() {
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size();
		bool bad = false;
		for (int i = 0; i < n / 2; ++i)
			if (s[i] != s[i+n/2]) bad = true;
		cout << (bad || n%2==1 ? "NO" : "YES") << endl;
	}
}