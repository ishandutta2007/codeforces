#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vll a(n);
	vector<ll> cnts(60, 0);
	foru(i, 0, n) {
		cin >> a[i];
		foru(j, 0, 60)cnts[j] += ((a[i] >> j) & 1);
	}
	ll tot = 0;
	foru(i, 0, n) {
		ll poly = 0, pw = 1;
		foru(j, 0, 60) {
			if ((a[i] >> j) & 1) {
				poly += (n * pw);
				poly %= mod;
			}
			else {
				poly += (cnts[j] * pw);
				poly %= mod;
			}
			pw <<= 1;
			pw %= mod;
		}
		pw = 1;
		foru(j, 0, 60) {
			if ((a[i] >> j) & 1) {
				tot += ((((poly * pw) % mod) * cnts[j]) % mod);
				tot %= mod;
			}
			pw <<= 1;
			pw %= mod;
		}
	}
	cout << tot << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}