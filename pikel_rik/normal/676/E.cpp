#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n + 1);
	for (int i = 0; i <= n; i++) {
		string s;
		cin >> s;
		if (s == "?") {
			a[i] = inf;
		} else {
			a[i] = stoi(s);
		}
	}

	int c = count(a.begin(), a.end(), inf);

	if (k == 0) {
		if (a[0] == inf) {
			cout << ((n - c) % 2 == 0 ? "Yes" : "No") << '\n';
		} else {
			cout << (a[0] == 0 ? "Yes" : "No") << '\n';
		}
	} else if (c > 0) {
		cout << (n % 2 != 0 ? "Yes" : "No") << '\n';
	} else {
		vector<int> primes = {
				68615147,
				15626719,
				35266927,
				62083981,
				47723483,
				42146917,
				85162513,
				72196679,
				56964881,
				52827791
		};

		bool ok = true;

		for (int p : primes) {
			int pow = 1, ans = 0;
			for (int i = 0; i <= n; i++) {
				ans = (ans + (ll) a[i] * pow) % p;
				pow = (ll) pow * k % p;
			}
			ok &= !ans;
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
	return 0;
}