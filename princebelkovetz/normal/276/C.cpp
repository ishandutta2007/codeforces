#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(2);
	int n, q; cin >> n >> q;
	vector <int> a(n), freq(n + 1);
	for (auto& x : a) cin >> x;
	while (q --> 0) {
		int l, r; cin >> l >> r;
		freq[--l]++;
		freq[r]--;
	}
	int cursum = 0;
	for (int i = 0; i < n; ++i) {
		freq[i] += cursum;
		cursum = freq[i];
	}
	sort(freq.rbegin(), freq.rend());
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for (int i = 0; i < n; ++i) ans += a[i] * freq[i];
	cout << ans << endl;

}