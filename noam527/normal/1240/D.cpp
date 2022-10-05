#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

ll pw(ll b, ll e, const int mod) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % mod;
		e /= 2, b = b * b % mod;
	}
	return rtn;
}

ll inv(ll x, const int mod) {
	return pw(x, mod - 2, mod);
}

const int M[2] = { 998244353, (int)1e9 + 9 };
const ll H[2] = { 1000003LL, 1000033LL };
ll I[2] = { inv(H[0], M[0]), inv(H[1], M[1]) };

int n;
vector<int> a;
ll ans = 0;

void solve(int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid + 1, r);

	if (OO) cout << "solving " << l << " " << r << '\n';

	vector<pair<ll, ll>> A, B;
	vector<int> st;
	ll ha[2];
	ha[0] = ha[1] = 0;
	for (int i = mid; i >= l; i--) {
		if (!st.size() || st.back() != a[i]) {
			for (int ty = 0; ty < 2; ty++)
				ha[ty] = (ha[ty] * H[ty] + a[i]) % M[ty];
			st.push_back(a[i]);
		}
		else {
			int val = st.back();
			st.pop_back();
			for (int ty = 0; ty < 2; ty++) {
				ha[ty] -= val;
				if (ha[ty] < 0) ha[ty] += M[ty];
				ha[ty] = (ha[ty] * I[ty]) % M[ty];
			}
		}
		A.emplace_back(ha[0], ha[1]);
	}
	st.clear();
	ha[0] = ha[1] = 0;
	for (int i = mid + 1; i <= r; i++) {
		if (!st.size() || st.back() != a[i]) {
			for (int ty = 0; ty < 2; ty++)
				ha[ty] = (ha[ty] * H[ty] + a[i]) % M[ty];
			st.push_back(a[i]);
		}
		else {
			int val = st.back();
			st.pop_back();
			for (int ty = 0; ty < 2; ty++) {
				ha[ty] -= val;
				if (ha[ty] < 0) ha[ty] += M[ty];
				ha[ty] = (ha[ty] * I[ty]) % M[ty];
			}
		}
		B.emplace_back(ha[0], ha[1]);
	}
	if (OO) {
		cout << "A B\n";
		for (const auto &i : A) cout << i.first << " " << i.second << '\n'; cout << '\n';
		for (const auto &i : B) cout << i.first << " " << i.second << '\n'; cout << '\n';
	}
	sort(B.begin(), B.end());
	for (const auto &i : A)
		ans += upper_bound(B.begin(), B.end(), i) - lower_bound(B.begin(), B.end(), i);
}

ll solve() {
	ans = 0;

	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	solve(0, n - 1);
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) cout << solve() << '\n';
}