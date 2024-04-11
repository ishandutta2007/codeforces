#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a[4], ans=0;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> n;
	for (int i=1; i<16; ++i) {
		int g=1;
		for (int j=0; j<4; ++j)
			if (i&1<<j)
				g=g*a[j]/__gcd(g, a[j]);
		ans+=(__builtin_popcount(i)%2?1:-1)*(n/g);
	}
	cout << ans;
	return 0;
}