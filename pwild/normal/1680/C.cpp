#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	int n = size(s);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i]-'0';
	}

	int sum = accumulate(begin(a), end(a), 0);
	
	int kmin = -1, kmax = size(s);
	while (kmax-kmin > 1) {
		int k = (kmin+kmax)/2;
		bool ok = false;
		int i = 0, j = 0, z = 0;
		while (i < n) {
			while (j < n && z+!a[j] <= k) {
				z += !a[j++];
			}
			int o = j-i-z;
			if (sum-o <= k) {
				ok = true;
			}
			z -= !a[i++];
		}
		(ok ? kmax : kmin) = k;
	}
	cout << kmax << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}