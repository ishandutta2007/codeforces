#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	string s; cin >> s;
	std::vector<int> v(n + 1, 0);
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v[i] = 1;
			v[n / i] = 1;
		} 
	}
	for (int i = n; i >= 0; --i) {
		if (!v[i]) continue;
		v[i] = n / i;
		for (int j = i * 2; j <= n; j += i) v[i] -= v[j];
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (!v[i]) continue;
		bool ok = true;
		for (int j = 0; j < i; ++j) {
			int jj = j;
			int cn = 0;
			do {
				if (s[jj] == '1')
					cn++; 
				jj = (jj + i) % n;
			} while(jj != j);
			if (cn & 1ll) {
				ok = false;
				break;
			} 
		} 
		if (ok)
			ans += v[i];
	}
	cout << ans;
}