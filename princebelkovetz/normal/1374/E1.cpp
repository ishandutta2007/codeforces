#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int n, k, ans = 0; cin >> n >> k;
	int sumBob = 0, sumAlice = 0;
	vector <int> a11, a10, a01;
	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		sumBob += a;
		sumAlice += b;
		if (a and b) a11.push_back(t);
		if (a and !b) a10.push_back(t);
		if (!a and b) a01.push_back(t);
		if (a or b) ans += t;
	}
	if (sumBob < k or sumAlice < k) {
		cout << -1;
		return 0;
	}
	sort(a11.begin(), a11.end());
	sort(a10.begin(), a10.end());
	sort(a01.begin(), a01.end());
	if (sumBob > sumAlice) {
		while (sumBob != sumAlice) {
			sumBob--;
			ans -= a10[a10.size() - 1];
			a10.pop_back();
		}
	}
	else if (sumBob < sumAlice) {
		while (sumBob != sumAlice) {
			sumAlice--;
			ans -= a01[a01.size() - 1];
			a01.pop_back();
		}
	}
	while (sumBob != k) {
		sumBob--;
		int x = 0, y = 0;
		if (a11.size()) x = a11[a11.size() - 1];
		if (a10.size()) y = a10[a10.size() - 1] + a01[a01.size() - 1];
		if (x > y) a11.pop_back();
		else {
			a10.pop_back();
			a01.pop_back();
		}
		ans -= max(x, y);
	}

	
	cout << ans << endl;
	return 0;
}