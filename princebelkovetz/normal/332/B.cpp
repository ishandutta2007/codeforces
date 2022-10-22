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
struct op {
	int l, r, d;
};
void solve() {
	int n, k, sum = 0, id1, id2, id3;
	cin >> n >> k;
	vector <int> a(n), pref(n + 1);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		pref[i + 1] = pref[i] + a[i];
	}
	int maxb = pref[n] - pref[n - k];
	id3 = n - k;
	for (int i = n - 2 * k; i >= 0; i--) {
		int a = pref[i + k] - pref[i];
		int b = pref[i + 2 * k] - pref[i + k];
		//debug(i); debug(a); debug(b); debug(maxb);
		if (b >= maxb) {
			maxb = b;
			id3 = i + k;
		}
		if (a + maxb >= sum) {
			id1 = i;
			id2 = id3;
			sum = a + maxb;
		}
	}
	cout << id1 + 1 << " " << id2 + 1 << endl;



}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}