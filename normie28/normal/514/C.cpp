#include <bits/stdc++.h>
using namespace std;
const int N = 7e5 + 5;
const long long p[2] = {5LL, 7LL};
const long long mod[2] = {(long long)1e9 + 7, (long long)1e9 + 9};
long long pw[2][N];
pair < long long, long long > hsh[N];
string tmp;
int n;
int q;
 
long long mod_add (long long a, long long b, long long mod) {
	return (a + b) % mod;
}
 
long long mod_sub (long long a, long long b, long long mod) {
	return (a - b + mod) % mod;
}
 
long long mod_mul (long long a, long long b, long long mod) {
	return (a * b) % mod;
}
 
pair < long long, long long > compute_hash () {
	long long tmp1 = 0;
	long long tmp2 = 0;
	for (int i = 0, sz = tmp.size(); i < sz; ++i) {
		tmp1 = mod_add(tmp1, mod_mul(pw[0][i], tmp[i], mod[0]), mod[0]);
		tmp2 = mod_add(tmp2, mod_mul(pw[1][i], tmp[i], mod[1]), mod[1]);
	}
	return make_pair(tmp1, tmp2);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	pw[0][0] = 1;
	pw[1][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < 2; ++j) {
			pw[j][i] = mod_mul(pw[j][i - 1], p[j], mod[j]);
		}
	}
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		hsh[i] = compute_hash();
	}
	sort(hsh, hsh + n);
	while (q--) {
		cin >> tmp;
		auto h = compute_hash();
		bool ok = 0;
		for (int i = 0, sz = tmp.size(); i < sz && !ok; ++i) {
			long long h1 = mod_sub(h.first, mod_mul(pw[0][i], tmp[i], mod[0]), mod[0]);
			long long h2 = mod_sub(h.second, mod_mul(pw[1][i], tmp[i], mod[1]), mod[1]);
			for (char ch = 'a'; ch <= 'c'; ++ch) {
				if (ch == tmp[i]) {
					continue;
				}
				long long tp1 = mod_add(h1, mod_mul(pw[0][i], ch, mod[0]), mod[0]);
				long long tp2 = mod_add(h2, mod_mul(pw[1][i], ch, mod[1]), mod[1]);
				if (binary_search(hsh, hsh + n, make_pair(tp1, tp2))) {
					ok = 1;
					break;
				}
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}