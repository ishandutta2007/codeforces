#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll f, T;
ll t0;
ll atp[2][3];

ll myceil(ll a, ll b) {
	if (a <= 0)return 0;
	return a / b + (a%b != 0);
}

ll calc(ll _f, ll _T) {
	ll ret = 0, t1 = atp[1][1], a1 = atp[1][0], p1 = atp[1][2];
	if (_f*min(t0, t1) > _T)return -1;
	if (t0 <= t1)return 0;
	ll my = myceil(_f*t0 - _T, t0 - t1);
	return p1 * myceil(my, a1);
}

int main() {
	fast;
	ll bst = 1e18;
	cin >> f >> T >> t0;
	foru(i, 0, 2) {
		foru(j, 0, 3)cin >> atp[i][j];
	}
	foru(rep, 0, 2) {
		for (ll j = 0; atp[0][0] * j <= f; j++) {
			ll crp = j * atp[0][2];
			ll crf = f - atp[0][0] * j;
			ll crt = T - atp[0][0] * j*atp[0][1];
			if (crt < 0)break;
			ll ret = calc(crf, crt);
			if (ret != -1)bst = min(bst, crp + ret);
		}
		foru(j, 0, 3)swap(atp[0][j], atp[1][j]);
	}
	if (bst > 1e17) cout << -1 << '\n';
	else cout << bst << '\n';
	return 0;
}