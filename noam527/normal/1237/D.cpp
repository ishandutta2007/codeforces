#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<ll> a;
vector<int> U, D;

vector<ll> res;

ll calc(int i) {
	if (res[i] != -1) return res[i];
	if (U[i] == -1 && D[i] == -1) return res[i] = inf;
	if (U[i] == -1) return res[i] = D[i];
	if (D[i] == -1) return res[i] = calc(U[i]);
	if (D[i] < U[i]) return res[i] = D[i];
	return res[i] = calc(U[i]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(2 * n);
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i + n] = a[i];
	U.resize(2 * n);
	D.resize(2 * n);
	vector<pair<ll, int>> st;

	st.clear();
	for (int i = 2 * n - 1; i >= 0; i--) {
		while (st.size() && st.back().first <= a[i]) st.pop_back();
		if (!st.size()) U[i] = -1;
		else U[i] = st.back().second;
		st.emplace_back(a[i], i);
	}
	st.clear();
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (OO) {
			cout << "start " << i << '\n';
			for (const auto &i : st) cout << i.first << " " << i.second << '\n';
		}
		while (st.size() && st.back().first >= 2 * a[i]) st.pop_back();
		auto it = lower_bound(st.begin(), st.end(), make_pair(a[i], -1));
		if (it == st.begin()) D[i] = -1;
		else {
			it--;
			D[i] = it->second;
		}
		st.emplace_back(2 * a[i], i);
	}
	for (int i = 0; i < n; i++) {
		if (U[i] == -1) U[i + n] = -1;
		else if (U[i] < n) U[i + n] = U[i] + n;
		else U[i + n] = U[i] - n;

		if (D[i] == -1) D[i + n] = -1;
		else if (D[i] < n) D[i + n] = D[i] + n;
		else D[i + n] = D[i] - n;
	}
	if (OO) {
		for (int i = 0; i < 2 * n; i++) cout << U[i] << " "; cout << '\n';
		for (int i = 0; i < 2 * n; i++) cout << D[i] << " "; cout << '\n';
	}

	res.resize(2 * n, -1);
	for (int i = 0; i < n; i++) {
		ll v = calc(i);
		if (v == inf) cout << "-1 ";
		else cout << (v - i + 2 * n) % (2 * n) << " ";
	}
}