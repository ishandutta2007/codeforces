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

	int n;
	cin >> n;

	ll fact = 1;
	for (int i = 1; i < n; i++) fact *= i;

	fact /= n / 2;
	cout << fact << '\n';
	return 0;
}