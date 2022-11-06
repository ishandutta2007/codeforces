#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int p(int n, int k) {
	int u = 0;
	while (n != 0) {
		if (n % k == 0) {
			n /= k;
			u++;
		} else {
			u += (n % k);
			n -= (n % k);
		}
	}
	return u;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int k; cin >> k;
		cout << p(n, k) << "\n";
	}
}