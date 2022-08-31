#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int n, k;
ll fact[17];

int cnt = 0;

void get_lucky(ll num) {
	if (num >= max(1, n - 15)) {
		return;
	}
	cnt += num > 0;
	get_lucky(num * 10 + 4);
	get_lucky(num * 10 + 7);
}

bool isLucky(int x) {
	bool ok = true;
	while (x) {
		ok &= x % 10 == 4 || x % 10 == 7;
		x /= 10;
	}
	return ok;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = 1;
	for (int i = 1; i <= 16; i++) {
		fact[i] = i * fact[i - 1];
	}

	cin >> n >> k; --k;
	int l = max(1, n - 15), r = n;

	if (n <= 15 && fact[n] <= k) {
		cout << "-1\n";
		return 0;
	}

	int m = r - l + 1;
	vector<int> num(m), value(m);

	for (int i = 1; i <= m; i++) {
		num[i - 1] = k % i;
		k /= i;
	}

	vector<int> v(m);
	iota(v.begin(), v.end(), 0);

	for (int i = m - 1; i >= 0; i--) {
		value[i] = v[num[i]];
		v.erase(v.begin() + num[i]);
	}
	reverse(value.begin(), value.end());

	get_lucky(0);
	for (int i = l; i <= r; i++) {
		cnt += isLucky(i) && isLucky(l + value[i - l]);
	}
	cout << cnt << '\n';
	return 0;
}