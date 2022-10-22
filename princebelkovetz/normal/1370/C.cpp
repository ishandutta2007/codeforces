#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "FastestFinger\n";
	}
	else if (n % 2 == 1 or n == 2) {
		cout << "Ashishgup\n";
	}
	else {
		for (int i = 3; i * i <= n; i++) {
			if (n % i == 0 and (n / i) % 2 == 0 and i % 2 == 1) {
				cout << "Ashishgup\n"; return;
			}
			if (n % i == 0 and (n / i) % 2 == 1 and i % 2 == 0) {
				cout << "Ashishgup\n"; return;
			}
		}
		cout << "FastestFinger\n";
	}

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}