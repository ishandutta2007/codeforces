#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	cin >> a;

	for (int i = a.length() - 1; i >= 0; i--) a += a[i];
	cout << a << '\n';
	return 0;
}