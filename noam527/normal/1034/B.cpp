#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll solve(ll n, ll m) {
	ll ans = 0;
	if (n == 1) {
		ans += (m / 6) * 6;
		m %= 6;
		if (m == 4) ans += 2;
		if (m == 5) ans += 4;
		return ans;
	}
	if (n == 2) {
		if (m == 2) return 0;
		if (m == 3) return 4;
		if (m % 2 == 0) return n * m;
		if (m == 7) return 12;
		return n * m;
	}
	if (m % 2 == 0 || n % 2 == 0) return n * m;
	return n * m - 1;
}

ll n, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	if (n > m) swap(n, m);
	cout << solve(n, m) << endl;
}