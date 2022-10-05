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

int n;
vector<ll> a, b;
ll ans = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n, 0);
	b.resize(n);
	for (ll i = 0, x; i < n; i++) {
		cin >> x;
		for (ll b = 1; b <= x; b *= 2)
			if (x & b) a[i]++;
//		cout << a[i] << endl;
	}
	b[0] = a[0];
	for (int i = 1; i < n; i++) b[i] = b[i - 1] + a[i];
	ll c[2] = { 0, 0 };
	for (int i = 121; i < n; i++) {
		if (i == 121) c[0]++;
		else c[b[i - 122] & 1]++;
		ans += c[b[i] & 1];
	}

	ll s, mx;
	for (int i = 0; i < n; i++) {
		s = 0;
		mx = 0;
		for (int j = i; j < min(n, i + 121); j++) {
			s += a[j];
			mx = max(mx, a[j]);
			if (s % 2 == 0 && 2 * mx <= s) ans++;
		}
	}
	cout << ans << endl;
}