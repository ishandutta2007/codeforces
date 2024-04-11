#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int check(string s) {
	string w = s;
	reverse(s.begin(), s.end());
	return (w != s);
}

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; i+j <= n; j++) {
			if (check(s.substr(i, j))) {ans = max(ans, j);}
		}
	}
	cout << ans;
	
	return 0;
}