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
	int l, r; cin >> l >> r;
	for (int i = l; i < r + 1; ++i) {
		set <int> u;
		int x = i, ok = 0;
		while (x){
			u.insert(x % 10);
			++ok;
			x /= 10;
		}
		if (u.size() == ok) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1;
	return 0;
}