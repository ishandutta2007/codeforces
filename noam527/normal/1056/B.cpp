#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll n, m;
ll ans = 0;

int main() {
	fast;
	cin >> n >> m;
	if (n <= m) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
			if ((i * i + j * j) % m == 0) {
				ll c1 = 1 + (n - i) / m;
				ll c2 = 1 + (n - j) / m;
				ans += (c1 * c2);
			}
		}
		finish(ans);
	}
	for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) {
		if ((i * i + j * j) % m == 0) {
			ll c1 = 1 + (n - i) / m;
			ll c2 = 1 + (n - j) / m;
			ans += (c1 * c2);
		}
	}
	finish(ans);
}