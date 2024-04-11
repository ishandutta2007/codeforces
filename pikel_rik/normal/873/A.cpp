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

	int n, k, x;
	cin >> n >> k >> x;

	vector<int> a(n);
	for (int& i : a) cin >> i;

	for (int i = n - k; i < n; i++) {
		a[i] = x;
	}

	cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
	return 0;
}