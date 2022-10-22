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
		ll a, b;
		cin >> a >> b;
		if (b==1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << a << " " << (2*b-1)*a << " " << a*2*b << "\n";
	}
	return 0;
}