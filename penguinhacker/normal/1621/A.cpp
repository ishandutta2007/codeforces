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
		int n, k;
		cin >> n >> k;
		if ((n+1)/2<k) {
			cout << "-1\n";
			continue;
		}
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				cout << (i%2==0&&i==j&&i/2<k?'R':'.');
			}
			cout << "\n";
		}
	}
	return 0;
}