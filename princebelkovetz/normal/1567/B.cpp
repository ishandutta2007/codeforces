#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 3e6 + 5, bb = 32;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tt; cin >> tt;

	vector <int> x(N);
	for (int i = 1; i < N; ++i) {
		x[i] = x[i - 1] ^ i;
	}

	while (tt --> 0) {
		int a, b; cin >> a >> b;
		if (x[a - 1] == b) cout << a;
		else if ((x[a - 1] ^ b) == a) cout << a + 2;
		else cout << a + 1;
		cout << '\n';
	}
	return 0;
}