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

	int k;
	cin >> k;

	int mx = (1 << 18) - 1;
	int j = 32 - __builtin_clz(k | 1);

	cout << "2 3\n";
	cout << mx << ' ' << k << ' ' << 0 << '\n';
	cout << (1 << j) << ' ' << ((1 << j) | k) << ' ' << k << '\n';
	return 0;
}