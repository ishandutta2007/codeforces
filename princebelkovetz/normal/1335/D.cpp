#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" )
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	vector <string> s(9);
	for (int i = 0; i < 9; ++i) cin >> s[i];
	s[0][0] = s[0][1];
	s[1][3] = s[1][4];
	s[2][6] = s[2][7];
	s[3][1] = s[3][2];
	s[4][4] = s[4][5];
	s[5][7] = s[5][8];
	s[6][2] = s[6][3];
	s[7][5] = s[7][6];
	s[8][8] = s[8][0];
	for (auto x : s) cout << x << endl;

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