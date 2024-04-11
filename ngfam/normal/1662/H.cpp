#include <bits/stdc++.h>
using namespace std;

#define int long long

void get_div(int n, set<int> &st) {
	for (int i = 1; i*i <= n; i++) {
		if ((n % i) == 0) {
			st.insert(i);
			st.insert(n/i);
		}
	}
}

void solve() {
	int n, m; cin >> n >> m;
	set<int> st;
	
	get_div(__gcd(n, m-2), st);
	get_div(__gcd(n, __gcd(n-2, m-1)), st);
	get_div(__gcd(n, __gcd(n-1, __gcd(m-1, m-2))), st);

	get_div(__gcd(n-1, m-1), st);
	get_div(__gcd(n-1, __gcd(m, m-2)), st);
	get_div(__gcd(n-1, __gcd(m, __gcd(m-1, n-2))), st);

	get_div(__gcd(n-2, m), st);

	cout << st.size();
	for (int i: st) cout << ' ' << i;
		cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}