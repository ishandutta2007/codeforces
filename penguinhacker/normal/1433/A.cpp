#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int dig = s[0] - '0';
		int num = s.size();
		cout << (dig - 1) * 10 + num * (num + 1) / 2 << "\n";
	}
	return 0;
}