#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int u, v;
bool cont;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> u >> v;
	if (u > v) {
		cout << "-1\n";
		return 0;
	}
	if (!u && !v) {
		cout << "0\n";
		return 0;
	}
	int d = v - u;
	if (d & 1ull) {
		cout << "-1\n";
		return 0;
	}
 	vector<int> tv;
	for (int i = 1; i < 64; i++)
		if (d & (1ull<<i))
			tv.push_back(i - 1);
	int lhs = 0, rhs = 0;
	for (int i : tv) {
		if (!cont && !(u & (1ull<<i))) {
			u |= (1ull<<i);
			cont = 1;
			lhs |= 1ull<<i;
		} else lhs |= 1ull<<i, rhs |= 1ull<<i;
	}
	if (!(u & lhs)) lhs |= u, u = 0;
	if (!(lhs & rhs)) lhs |= rhs, rhs = 0;
	if (!(u & rhs)) u |= rhs, rhs = 0;
	cout << !!u + !!lhs + !!rhs << '\n';
	if (u) cout << u << ' ';
	if (lhs) cout << lhs << ' ';
	if (rhs) cout << rhs << ' ';
	cout << '\n';
}