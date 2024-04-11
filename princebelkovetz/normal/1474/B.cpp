#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int N = 1e5;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	vector <int> resh(N);
	set <int> p;
	for (int i = 2; i < N; ++i) {
		if (!resh[i]) {
			p.insert(i);
			for (int j = i * i; j < N; j += i) resh[j] = 1;
		}
	}
	int tt; cin >> tt;
	while (tt --> 0) {
		int d; cin >> d;
		int x = *p.lower_bound(1 + d);
		int y = *p.lower_bound(x + d);
		cout << x * y << '\n';
	}
	return 0;
}