#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int mod = 1e9 + 7;
int n;
vector <int> got;
vector <bool> used;
void query(int i) {
	int id1 = i, id2 = (i + n / 2) % n;
	int x;
	if (!used[id1]) {
		cout << "? " << id1 + 1 << endl;
		cin >> x;
		used[id1] = true, got[id1] = x;
	}
	if (!used[id2]) {
		cout << "? " << id2 + 1 << endl;
		cin >> x;
		used[id2] = true, got[id2] = x;
	}
}
int sign(int x) {
	return (x > 0) - (x < 0);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	got.resize(n);
	used.resize(n);
	if (n % 4) {
		cout << "! -1" << endl;
		return 0;
	}
	query(0);
	if (got[0] == got[n / 2]) {
		cout << "! 1" << endl;
		return 0;
	}
	int l = 1, r = n / 2;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		query(m);
		if (sign(got[m] - got[m + n / 2]) == sign(got[0] - got[n / 2])) {
			l = m;
		}
		else r = m;
	}
	cout << "! " << r + 1 << endl;
	return 0;
}