#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 5e5;
pii ab[sz];
int n;
int loc[sz], other[sz];
int mnp[sz], mxs[sz];

void init() {
	for (int i = 1; i <= n; i++) {
		mnp[i] = (i == 1 ? other[i] : min(mnp[i - 1], other[i]));
	}
	for (int i = n; i >= 1; i--) {
		mxs[i] = (i == n ? other[i] : max(mxs[i + 1], other[i]));
	}
}

int foo(const vector<int>& v) {
	int m = v.size();
	if (m == 1)return 0;
	vector<bool> isa(m, 0);
	isa[0] = 1;
	int ca = other[v[0]], cb = 1e9;
	foru(i, 1, m) {
		if (other[v[i]] < ca) {
			isa[i] = 1;
			ca = other[v[i]];
		}
		else if (other[v[i]] < cb) {
			isa[i] = 0;
			cb = other[v[i]];
		}
		else return -1;
	}
	int cnt1 = 0, cnt2 = 0;
	foru(i, 0, m) {
		if (isa[i]) {
			if (ab[loc[other[v[i]]]].ff != other[v[i]])cnt1++;
			else cnt2++;
		}
		else {
			if (ab[loc[other[v[i]]]].ss != other[v[i]])cnt1++;
			else cnt2++;
		}
	}
	return min(cnt1, cnt2);
}

int main() {
	fast;
	bool bad = 0;
	cin >> n;
	foru(i, 0, n) {
		cin >> ab[i].ff >> ab[i].ss;
		bad |= (ab[i].ff <= n && ab[i].ss <= n);
		loc[ab[i].ff] = loc[ab[i].ss] = i;
		if (ab[i].ff <= n)other[ab[i].ff] = ab[i].ss;
		if (ab[i].ss <= n)other[ab[i].ss] = ab[i].ff;
	}
	if (bad) {
		cout << -1 << '\n';
		return 0;
	}
	int ret = 0;
	init();
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.pb(i);
		if (mnp[i] > mxs[i + 1]) {
			int tmp = foo(v);
			if (tmp != -1)ret += tmp;
			else {
				cout << -1 << '\n';
				return 0;
			}
			v.clear();
		}
	}
	cout << ret;
	return 0;
}