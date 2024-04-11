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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e3;
ll dp[sz];

ll solve(ll n) {
	ll tot = 0;
	bool me = 1;
	while (n) {
		if (n & 1) {
			n--;
			if (me)tot++;
		}
		else {
			if (n % 4 == 0 && n != 4) {
				n--;
				if (me)tot++;
			}
			else {
				if (me)tot += (n >> 1);
				n >>= 1;
			}
		}
		me = !me;
	}
	return tot;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}