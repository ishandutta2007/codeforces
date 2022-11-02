#define _CRT_SECURE_NO_WARNINGS
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
#include <bitset>
#include <queue>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll k;
vector<ll> baseCase;
ll ten[20], sum[20];

void prec() {
	ten[0] = 1;
	for (int i = 1; i <= 18; i++)ten[i] = ten[i - 1] * 10;
	baseCase.pb(0);
	for (ll digs = 1; digs <= 15; digs++) {
		ll prv = baseCase.back();
		baseCase.pb(9 * ten[digs - 1] * digs + prv);
	}
	sum[0] = 0;
	for (ll digs = 1; digs <= 9; digs++) {
		ll howMany = 9 * ten[digs - 1];
		sum[digs] = sum[digs - 1] + baseCase[digs - 1] * howMany + digs * (howMany*(1 + howMany)) / 2;;
	}
}

ll find(ll n) {
	for (ll i = 1; i <= 10; i++) {
		if (n <= i * ten[i - 1] * 9) {
			ll mynum = ten[i - 1] + n / i;
			if (n%i == 0)return (mynum - 1) % 10;
			else return ((to_string(mynum))[n%i - 1]-'0');
		}
		else n -= i * ten[i - 1] * 9;
	}
	return -1;
}

ll getR(ll digs) {
	ll ret = 1e10;
	if (digs != 1)ret = min(ret, (ll)1e18 / baseCase[digs - 1]);
	ret = min(ret,ten[digs - 1] * 9);
	return ret;
}

ll solve() {
	cin >> k;
	if (k == 1)return 1;
	for (int i = 1; i <= 9; i++) {
		if (k <= sum[i]) {
			k -= sum[i - 1];
			ll l = 1, r = getR(i) , bst = 0, mid, tmp;
			while (l <= r) {
				mid = (l + r + 1) / 2;
				tmp = baseCase[i-1] * mid + i * (((1 + mid)*mid) / 2);
				if (tmp < k) {
					bst = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			tmp= baseCase[i - 1] * bst + i * (((1 + bst)*bst) / 2);
			k -= tmp;
			return find(k);
		}
	}
	return -1;
}


int main() {
	fast;
	prec();
	int q;
	cin >> q;
	while (q--)cout << solve() << endl;
	return 0;
}