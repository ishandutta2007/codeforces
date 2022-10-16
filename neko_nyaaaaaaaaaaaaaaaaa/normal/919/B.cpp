#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumd(ll n) {
	ll ans = 0;
	while (n) {
		ans += n % 10;
		n/= 10;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	
	ll k = 0;
	ll n, i;
	cin >> n;
	for (i = 18; k < n; i++) {
		if (sumd(i) == 10) {k++;}
	}
	cout << i-1;
	
	return 0;
}