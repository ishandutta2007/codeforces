#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;



int n, m;

int main() {
	fast;
	cin >> n >> m;
	vector<ll> a(n);
	foru(i, 0, n)cin >> a[i];
	if (n != 1) {
		sort(a.begin(), a.end());
		ll g = a[1] - a[0];
		foru(i, 1, n)g = gcd(g, a[i] - a[0]);
		while (m--) {
			ll tmp;
			cin >> tmp;
			cout << gcd(g, a[0] + tmp) << ' ';
		}
	}
	else {
		while (m--) {
			ll x;
			cin >> x;
			cout << a[0] + x << ' ';
		}
	}
	return 0;
}