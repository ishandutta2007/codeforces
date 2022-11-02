#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <math.h>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
ll a[sz], n, parr[sz], b[sz];

vector<ll> foo(ll x) {
	vector<ll> ans;
	for (ll i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			ans.pb(i);
			while (x%i == 0) x /= i;
		}
	}
	if (x != 1)ans.pb(x);
	return ans;
}


int main() {
	fast;
	ll sm = 0;
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i]; sm += a[i];
		parr[i] = a[i] + (i ? parr[i - 1] : 0);
	}
	vector<ll> dec = foo(sm);
	if (dec.empty()) {
		cout << -1 << endl;
		return 0;
	}
	ll bst = 1e18;
	for (ll p : dec) {
		foru(i, 0, n)b[i] = parr[i];
		ll tot = 0;
		foru(i, 0, n - 1) {
			tot += min((p - b[i] % p) % p, b[i] % p);
		}
		bst = min(bst, tot);
	}
	cout << bst << endl;
	return 0;
}