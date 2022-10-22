#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.size();
		int l = 696969, r = -1;
		for (int i = n - 2; ~i; --i)
			if (s[i] == '1' && s[i - 1] == '1')
				l = i - 1;
		for (int i = 1; i < n; ++i)
			if (s[i] == '0' && s[i + 1] == '0')
				r = i + 1;
		cout << (l > r ? "YES" : "NO") << "\n";
	}
	return 0;
}