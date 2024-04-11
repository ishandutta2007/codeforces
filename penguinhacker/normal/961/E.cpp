#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T, int n> struct BIT { //try to always use long long
	vector<T> bit;
	BIT() {
		bit.resize(n + 1);
		for (int i = 0; i < n; ++i) upd(i, 1);
	}
	void upd(int i, T val) {
		for (++i; i <= n; i += i & -i)
			bit[i] += val;
	}
	T qry(int i) {T res = 0;
		for (++i; i > 0; i -= i & -i)
			res += bit[i];
		return res;
	}
	T qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
};

int n, a[200000];
vector<pair<int, int>> v;
BIT<int, 200000> b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		v.emplace_back(a[i], i);
	}
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		while(!v.empty() && v.back().first < i) {
			b.upd(v.back().second, -1);
			v.pop_back();
		}
		ans += max(0, b.qry(i + 1, min(n - 1, a[i])));
	}
	cout << ans;
	return 0;
}