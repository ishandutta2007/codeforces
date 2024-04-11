#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		int zeroes = 0;
		for (auto& x : s)
			zeroes += (x == '0');
		if (!zeroes) {
			cout << "DRAW";
		}
		else if (zeroes == 1 or zeroes & 1 ^ 1) {
			cout << "BOB";
		}
		else cout << "ALICE";
		cout << '\n';
	}
}