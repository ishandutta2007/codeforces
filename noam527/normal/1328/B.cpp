#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
string s;

void solve() {
	cin >> n >> k;
	s.clear();
	s.resize(n, 'a');
	for (int i = 1; i < n; i++) {
		if (k <= i) {
			s[i] = 'b';
			s[k - 1] = 'b';
			break;
		}
		k -= i;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}