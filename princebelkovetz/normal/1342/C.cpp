#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 998244353;
int bpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return (a * bpow(a, b - 1)) % mod;
	int t = bpow(a, b / 2);
	return (t * t) % mod;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int a, b, q;
		cin >> a >> b >> q;
		vector <int> ok(a * b + 1);
		for (int i = 1; i <= a * b; ++i) {
			ok[i] = ok[i - 1];
			if ((i % a) % b != (i % b) % a) 
				ok[i]++;
		}
		while (q --> 0) {
			int l, r; cin >> l >> r;
			--l;
			int ansl = ok[a * b] * (l / (a * b)) + ok[l % (a * b)];
			int ansr = ok[a * b] * (r / (a * b)) + ok[r % (a * b)];
			cout << ansr - ansl << ' ';
		}
		cout << '\n';
	}
	return 0;
}