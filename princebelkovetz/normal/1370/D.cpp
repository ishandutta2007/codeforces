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
void solve() {
	int n, k; cin >> n >> k;
	vector <int> a(n); 
	for (int i = 0; i < n; ++i) cin >> a[i];
	int l = 0, r = 1e9 + 1, m;
	while (l + 1 < r) {
		//debug(l); debug(r);
		m = (l + r) / 2;
		bool FlagShtock = false;
		int curlen1 = 0, curlen2 = 0;
		for (int i = 0; i < n; ++i) {
			if (curlen1 % 2 == 0) curlen1++;
			else if (a[i] <= m) curlen1++;
		}
		for (int i = 0; i < n; ++i) {
			if (curlen2 % 2 == 1) curlen2++;
			else if (a[i] <= m) curlen2++;
		}
		if (curlen1 >= k or curlen2 >= k) r = m;
		else l = m;
	}
	if (r == 1e9 + 1) r = l;
	cout << r << endl;

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; t = 1;
	while (t--) {
		solve();
	}
	return 0;
}