#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll INF = 1e15;

void solve() {
	int n;
	cin >> n;
	ll mnl = INF, mxr = -INF;
	ll cl = INF, cr = INF, cc = INF;
	foru(i, 0, n) {
		ll l, r, c;
		cin >> l >> r >> c;
		if (l < mnl) {
			mnl = l;
			cl = c;
			cc = INF;
		}
		else if (l == mnl) {
			cl = min(cl, c);
		}
		if (r > mxr) {
			mxr = r;
			cr = c;
			cc = INF;
		}
		else if (r == mxr) {
			cr = min(cr, c);
		}
		if (l == mnl && r == mxr) {
			cc = min(cc, c);
		}
		cout << min(cc, cl + cr) << '\n';
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}