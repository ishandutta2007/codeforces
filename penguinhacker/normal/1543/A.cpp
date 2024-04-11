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
		if (a==b) {
			cout << "0 0\n";
			continue;
		}
		ll k=abs(a-b);
		ll d=a-a/k*k;
		cout << k << " " << min(d, k-d) << "\n";
	}
	return 0;
}