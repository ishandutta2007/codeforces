/** neko_nyaa's very long and elaborated template **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	ll ans = 1e18 + 1;
	for (int i = 0; i < n; i++) {
		ll tmp = -1e18 - 1;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			for (int k = 0; k < m; k++) {
				if (a[j]*b[k] > tmp) {tmp = a[j]*b[k];}
			}
		}
		if (tmp < ans) {ans = tmp;}
	}
	cout << ans;
	
	
	return 0;
}