#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		int last = -1;
		for (char c : s) {
			int x = c - '0';
			int cur = x + 1 != last ? 1 : 0;
			cout << cur;
			last = x + cur;
		}
		cout << "\n";
	}
	return 0;
}