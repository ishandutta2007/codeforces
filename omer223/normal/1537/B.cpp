
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


ll di(pii x, pii y) {
	return abs(x.ff - y.ff) + abs(x.ss - y.ss);
}

ll calcd(pii x, pii y, pii z) {
	return di(x, y) + di(y, z) + di(x, z);
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		int n, m, i, j;
		cin >> n >> m >> i >> j;
		ll bst = -1;
		vector<pii> bstd;
		vector<pii> cur{ {1,1},{n,m},{1,m},{n,1} };
		do {
			ll tmp = calcd({ i,j }, cur[0], cur[1]);
			if (tmp > bst) {
				bst = tmp;
				bstd = { cur[0],cur[1] };
			}
		} while (next_permutation(cur.begin(), cur.end()));
		cout << bstd[0].ff << ' ' << bstd[0].ss << ' ' << bstd[1].ff << ' ' << bstd[1].ss << '\n';
	}
	return 0;
}