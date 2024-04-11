#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	
	ll upbound = min(n, k-1);
	ll lowbound;
	
	if (k % 2 == 0) {
		lowbound = k/2 + 1;
	} else {
		lowbound = k/2 + 1;
	}
	
	cout << max(upbound - lowbound + 1, 0LL);
	
	return 0;
}