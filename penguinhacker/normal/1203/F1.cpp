#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, r;
vector<ar<int, 2>> pos, neg;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r;
	for (int i = 0, a, b; i < n; ++i) {
		cin >> a >> b;
		if (b >= 0)
			pos.push_back({a, b});
		else
			neg.push_back({a, b});
	}
	sort(pos.begin(), pos.end());
	for (ar<int, 2> x : pos) {
		if (r < x[0]) {
			cout << "NO";
			return 0;
		}
		r += x[1];
	}
	for (ar<int, 2>& x : neg)
		x[0] = max(x[0], -x[1]);
	sort(neg.begin(), neg.end(), [](ar<int, 2> a, ar<int, 2> b) {return a[0] + a[1] > b[0] + b[1];});
	for (ar<int, 2> x : neg) {
		if (r < x[0]) {
			cout << "NO";
			return 0;
		}
		r += x[1];
	}
	cout << "YES";
	return 0;
}