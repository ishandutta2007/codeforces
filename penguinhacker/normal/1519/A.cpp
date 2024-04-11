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
		ll a, b, c;
		cin >> a >> b >> c;
		if (a>b)
			swap(a, b);
		cout << (b<=a*(c+1)?"YES":"NO") << "\n";
	}
	return 0;
}