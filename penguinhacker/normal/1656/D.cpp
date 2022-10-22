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
		ll n;
		cin >> n;
		if (__builtin_popcountll(n)==1) {
			cout << "-1\n";
			continue;
		}
		ll x=1ll<<__builtin_ctzll(n);
		if (x<=1e9&&x*(2*x+1)<=n) {
			cout << 2*x << "\n";
			continue;
		}
		x=n/x;
		assert(x*(x+1)/2<=n);
		cout << x << "\n";
	}
	return 0;
}