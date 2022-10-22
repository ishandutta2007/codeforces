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
		int n;
		cin >> n;
		if (n == 1 || n == 2 || n == 4) {
			cout << "-1\n";
			continue;
		}
		if (n == 7) {
			cout << "0 0 1\n";
			continue;
		}
		int k = n % 3;
		if (k == 0) {
			cout << n / 3 << " 0 0\n";
		}
		else if (k == 1) {
			cout << (n - 10) / 3 << " 2 0\n";
		}
		else if (k == 2) {
			cout << (n - 5) / 3 << " 1 0\n";
		}
		else {
			assert(0);
		}
	}	
	return 0;
}