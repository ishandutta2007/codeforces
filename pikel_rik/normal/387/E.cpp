#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e6 + 5;

template<typename T>
struct FenwickTree {
	using F = function<T(const T&, const T&)>;

	int n;
	vector<T> bit;
	F f;
	FenwickTree() : n(), f() {}
	FenwickTree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

	void add(int i, T val) {
		for (; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}
	T query(int i) {
		T ans = 0;
		for (; i; i -= i & -i) {
			ans = f(ans, bit[i]);
		}
		return ans;
	}
};

int n, k, a[N], b[N], pos[N], l[N], r[N];
bool there[N];

bool comp(int i, int j) {
	return a[i] < a[j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i], --a[i], pos[a[i]] = i;

	for (int i = 0; i < k; i++) {
		cin >> b[i]; --b[i];
		there[b[i]] = true;
	}

	vector<int> st;
	for (int i = 0; i < n; i++) {
		if (there[a[i]]) {
			while (!st.empty() && a[st.back()] > a[i]) {
				st.pop_back();
			}
			l[i] = (st.empty() ? -1 : st.back());
			st.push_back(i);
		} else {
			int j = (upper_bound(st.begin(), st.end(), i, comp) - st.begin()) - 1;
			if (j >= 0) {
				l[i] = st[j];
			} else {
				l[i] = -1;
			}
		}
	}

	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		if (there[a[i]]) {
			while (!st.empty() && a[st.back()] > a[i]) {
				st.pop_back();
			}
			r[i] = (st.empty() ? n : st.back());
			st.push_back(i);
		} else {
			int j = (upper_bound(st.begin(), st.end(), i, comp) - st.begin()) - 1;
			if (j >= 0) {
				r[i] = st[j];
			} else {
				r[i] = n;
			}
		}
	}

	FenwickTree<int> ft(n);
	for (int i = 0; i < n; i++) {
		ft.add(i + 1, 1);
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (there[i]) continue;
		ans += ft.query(r[pos[i]]) - ft.query(l[pos[i]] + 1);
		ft.add(pos[i] + 1, -1);
	}
	cout << ans << '\n';
	return 0;
}