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
		if (n==1) {
			cout << "2\n";
			continue;
		}
		cout << (n+2)/3 << "\n";
	}
	return 0;
}