#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		string s, t; cin >> s >> t;
		int lcm = s.size() * t.size() / __gcd(s.size(), t.size());
		string a, b;
		for (int i = 0; a.size() < lcm;) a += s;
		for (int i = 0; b.size() < lcm;) b += t;
		cout << (a == b ? a : "-1") << "\n";
	}
	return 0;
}