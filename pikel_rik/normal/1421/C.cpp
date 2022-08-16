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

	string s;
	cin >> s;
	s = ' ' + s;

	cout << 3 << '\n';
	cout << 'L' << ' ' << 2 << '\n';//++
	cout << 'R' << ' ' << 2 << '\n';//+=n - 1
	cout << 'R' << ' ' << 2 * s.length() - 3 << '\n';
	return 0;
}