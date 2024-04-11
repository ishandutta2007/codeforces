#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll foo(ll x) {
	ll sm = 0, tx = x;
	while (tx) {
		sm += (tx % 10);
		tx /= 10;
	}
	return gcd(sm, x);
}

void solve() {
	ll n;
	cin >> n;
	for (ll x = n;; x++) {
		if (foo(x) != 1) {
			cout << x << '\n';
			return;
		}
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}