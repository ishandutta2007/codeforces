#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 6e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int bcount(ll x) {
	int v = 0;
	for (ll i = 0; (1LL << i) <= x; i++)
		if (x & (1LL << i)) v++;
	return v;
}

int n, m;
vector<ll> a;

vector<ll> yes, no;

int C[1 << 17][60];
int stupid[60] = {};

void brute(int i, ll x) {
	if (i == n) {
		stupid[bcount(x)]++;
		return;
	}
	brute(i + 1, x);
	brute(i + 1, a[i] ^ x);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int b = 0;
	int row = 0;
	ll B = 1;
	while (b < m) {
		int at = -1;
		for (int i = row; i < n; i++) {
			if (a[i] & B) {
				at = i;
				break;
			}
		}
		if (at == -1) {
			no.push_back(B);
			b++;
			B *= 2;
			continue;
		}
		swap(a[row], a[at]);
		for (int i = row + 1; i < n; i++)
			if (a[i] & B)
				a[i] ^= a[row];
		yes.push_back(B);
		row++, b++, B *= 2;
	}
	int mult = 1;
	while (a.size() && a.back() == 0) {
		a.pop_back();
		mult = 2 * mult % md;
	}
	n = a.size();
	for (int i = n - 1; i >= 0; i--) {
		ll first = 1;
		while ((a[i] & first) == 0) first *= 2;
		for (int j = i - 1; j >= 0; j--)
			if (a[j] & first)
				a[j] ^= a[i];
	}

	if (OO) {
		cout << "result:\n";
		for (const auto &i : a) cout << i << " "; cout << endl;
	}

	n = a.size();
	if (no.size() < yes.size()) {
		int k = no.size();
		ll big = 0;
		for (auto &i : no)
			big |= i;

		if (OO) {
			cout << "in no, big = " << big << endl;
		}
		
		C[0][0] = 1;

		for (auto &v : a) {
			if (OO) {
				cout << "new iter " << v << endl;
				for (int mask = 0; mask < (1 << k); mask++) {
					for (int cnt = 0; cnt <= n; cnt++) cout << C[mask][cnt] << " "; cout << endl;
				}
				cout << endl;
			}
			ll tr = 0;
			for (int i = 0; i < k; i++)
				if (v & no[i])
					tr |= (1 << i);
			for (int cnt = n; cnt > 0; cnt--) {
				for (int mask = 0; mask < (1 << k); mask++) {
					C[mask][cnt] = (C[mask][cnt] + C[mask ^ tr][cnt - 1]) % md;
				}
			}
		}
		if (OO) {
			cout << "at last\n";
			for (int mask = 0; mask < (1 << k); mask++) {
				for (int cnt = 0; cnt <= n; cnt++) cout << C[mask][cnt] << " "; cout << endl;
			}
			cout << endl;
		}
		vector<int> ans(m + 1, 0);
		for (int mask = 0; mask < (1 << k); mask++) {
			int bcnt = 0;
			for (int j = 0; j < k; j++)
				if (mask & (1 << j)) bcnt++;
			for (int cnt = 0; cnt <= n; cnt++)
				if (bcnt + cnt <= m)
					ans[bcnt + cnt] = (ans[bcnt + cnt] + C[mask][cnt]) % md;
		}
		for (auto &i : ans)
			i = (ll)i * mult % md;
		for (const auto &i : ans) cout << i << " "; cout << endl;
		return 0;
	}

	brute(0, 0);
	for (int i = 0; i <= m; i++)
		stupid[i] = (ll)stupid[i] * mult % md;
	for (int i = 0; i <= m; i++)
		cout << stupid[i] << " "; cout << endl;
}