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

const int sz = 3e5;

ll n, a[sz];
ll del[sz];//del[i] == a[i] - a[i - 1];
ll p = 0;

inline ll foo(ll prv, ll up) {
	if (up > 0) {
		if (prv > 0)return up;
		else if (prv + up >= 0)return prv + up;
		else return 0;
	}
	else {
		if (prv < 0)return 0;
		else if (prv + up <= 0)return -prv;
		else return up;
	}
}

inline ll calc(ll x, ll y) {
	ll ta = x, tp = y, delt = max(0LL, max(-x, -y));
	ta += delt;
	tp += delt;
	ll ans = (ta + tp + 1) / 2;
	ans -= delt;
	return ans;
}


int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
		if (i&&a[i] > a[i - 1])p += (a[i] - a[i - 1]);
		if (i)del[i] = a[i] - a[i - 1];
	}
	cout << calc(a[0], p) << endl;
	ll q, l, r, v;
	cin >> q;
	while (q--) {
		cin >> l >> r >> v; l--; r--;
		if (!l)a[0] += v;
		if (l) {
			p += foo(del[l], v);
			del[l] += v;
		}
		if (r < n - 1) {
			p += foo(del[r + 1], -v);
			del[r + 1] -= v;
		}
		cout << calc(a[0], p) << endl;
	}
	return 0;
}