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
		ll x=n, p=1;
		while(x) {
			p*=10;
			x/=10;
		}
		cout << n-p/10 << "\n";
	}
	return 0;
}