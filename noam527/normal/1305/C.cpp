#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll pw(ll b, ll e, int m) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % m;
		e /= 2, b = b * b % m;
	}
	return rtn;
}

int n, m;
int a[1010];
ll ans = 1;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	if (n > m + 5) finish(0);
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
		ans = (ans * abs(a[i] - a[j])) % m;
	cout << ans << '\n';
}