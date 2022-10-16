#include <bits/stdc++.h>
using namespace std;
 
bitset<1000001> sieve;
vector<int> pr;
vector<int> tst(1000001, -1);
 
void init() {
	for (int i = 2; i <= 1000000; i++) {
		if (!sieve[i]) {
			for (long long j = 1LL*i*i; j <= 1000000; j += i) {
				sieve[j] = 1;
			}
			pr.push_back(i);
		}
	}
}
 
int ans = 1000000000;
 
int test(int &n, vector<long long> &a, int m) {
	int tmp = 0, gg;
	for (long long i: a) {
		if (i < m) {
			tmp += m-i;
		} else {
			int gg = i % m;
			tmp += min(gg, m - gg);
		}
 
		if (tmp > ans) return tmp;
	}
	return tmp;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); double t = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	init();
 
	int n; cin >> n;
	vector<long long> a(n);
	long long g = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; g = __gcd(g, a[i]);
	}
	if (g > 1) {cout << "0\n"; exit(0);}
 
	ans = min(test(n, a, 2), test(n, a, 3));
	if (ans <= 1) {cout << ans << '\n';}
 
	uniform_int_distribution<int> rngg(0, n-1);
	//cout << test(n, a, 2) << ' ' << test(n, a, 3) << endl;
	while ((clock() - t) / CLOCKS_PER_SEC < 2.3) {
		int k = rngg(rng);
 
		long long f = a[k];
		for (int i: pr) {
			if ((f % i) == 0) {
				while ((f % i) == 0) f /= i;
				ans = min(ans, test(n, a, i));
			}
		}
		if (f > 1) ans = min(ans, test(n, a, f));
 
		f = a[k]+1;
		for (int i: pr) {
			if ((f % i) == 0) {
				while ((f % i) == 0) f /= i;
				ans = min(ans, test(n, a, i));
			}
		}
		if (f > 1) ans = min(ans, test(n, a, f));
 		if (a[k] == 1) continue;
 
		f = a[k]-1;
		for (int i: pr) {
			if ((f % i) == 0) {
				while ((f % i) == 0) f /= i;
				ans = min(ans, test(n, a, i));
			}
		}
		if (f > 1) ans = min(ans, test(n, a, f));
	}
	cout << ans << '\n';
 
	return 0;
}