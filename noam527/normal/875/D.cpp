#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[200000];
vector<int> b(31), vl, vr, orl, orr;
vector<int> st;
ll ans = 0;

int main() {
	fast;
	cin >> n;
	vl.resize(n), vr.resize(n), orr.resize(n), orl.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	b.assign(31, -1);
	for (int i = 0; i < n; i++) {
		int mx = -1;
		for (int j = 1, at = 0; j < 1e9; j <<= 1, at++) {
			if (a[i] & j) b[at] = i;
			else mx = max(mx, b[at]);
		}
		orl[i] = mx;
	}
	b.assign(31, n);
	for (int i = n - 1; i >= 0; i--) {
		int mn = n;
		for (int j = 1, at = 0; j < 1e9; j <<= 1, at++) {
			if (a[i] & j) b[at] = i;
			else mn = min(mn, b[at]);
		}
		orr[i] = mn;
	}

	for (int i = 0; i < n; i++) {
		while (st.size() && a[i] >= a[st.back()]) st.pop_back();
		if (!st.size()) vl[i] = -1;
		else vl[i] = st.back();
		st.push_back(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (st.size() && a[i] > a[st.back()]) st.pop_back();
		if (!st.size()) vr[i] = n;
		else vr[i] = st.back();
		st.push_back(i);
	}

//	for (auto &i : orl) cout << i << " "; cout << endl;
//	for (auto &i : orr) cout << i << " "; cout << endl;
//	for (auto &i : vl) cout << i << " "; cout << endl;
//	for (auto &i : vr) cout << i << " "; cout << endl;

	for (int i = 0; i < n; i++) {
		ll tot = (ll)(i - vl[i]) * (vr[i] - i);
		orl[i] = max(orl[i], vl[i]);
		orr[i] = min(orr[i], vr[i]);
		ll tot2 = (ll)(i - orl[i]) * (orr[i] - i);
		ans += tot - tot2;
	}
	cout << ans << endl;
}