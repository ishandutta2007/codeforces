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
#include <queue>
#include <set>
#include <bitset>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
bitset<sz> se,p;

void sieve() {
	for (int i = 2; i <= 1e6; i++) {
		if (!se[i]) {
			se[i] = 1;
			p[i] = 1;
			for (int j = 2 * i; j <= 1e6; j += i)se[j] = 1;
		}
	}
}


int main() {
	fast;
	sieve();
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		if (n == 1) {
			cout << "NO" << endl;
			continue;
		}
		ll l = 1, r = 1e9, mid, sq;
		bool found = 0;
		while (l <= r) {
			mid = (l + r + 1) / 2;
			if (mid*mid < n) l = mid + 1;
			else if (mid*mid > n)r = mid - 1;
			else {
				found = 1;
				sq = mid;
				break;
			}
		}
		if (!found || !p[sq]) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
	return 0;
}