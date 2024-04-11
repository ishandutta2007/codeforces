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
		if (s.size() % 2 == 1) {
			cout << "NO\n";
			continue;
		}
		cout << (s[0] != ')' && s.back() != '(' ? "YES" : "NO") << "\n";
	}
	return 0;
}