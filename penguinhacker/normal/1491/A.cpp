#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, a[100000], cnt[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> a[i], ++cnt[a[i]];
	while(q--) {
		int t, x; cin >> t >> x;
		if (t == 1) {
			--cnt[a[--x]];
			a[x] ^= 1;
			++cnt[a[x]];
		}
		else if (t == 2) {
			cout << (cnt[1] >= x) << "\n";
		}
	}
	return 0;
}