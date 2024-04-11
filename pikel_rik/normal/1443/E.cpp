#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template<typename T>
struct SegmentTree {
	using F = function<T(const T&, const T&)>;

	int n;
	vector<T> t;
	T e;
	F f;
	SegmentTree() : n(), e(), f() {}

	template<typename U>
	SegmentTree(const U &arr, int n, T e, F f): n(n), t(2 * n), e(e), f(f) {
		for (int i = 0; i < n; i++)
			t[i + n] = T(arr[i]);
		for (int i = n - 1; i > 0; i--)
			t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	template<typename U>
	void update(int i, U val) {
		for (t[i += n] = T(val); i > 1; i >>= 1) {
			t[i >> 1] = f(t[i], t[i ^ 1]);
		}
	}

	T query(int l, int r) {
		T ans = e;
		for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = f(ans, t[l++]);
			if (r & 1) ans = f(ans, t[--r]);
		}
		return ans;
	}
};

const int N = 2e5 + 5;

int n, q, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	iota(a, a + N, 0);

	vector<int> init(min(n, 15)), last(min(n, 15));
	vector<ll> perm(min(n, 15));
	iota(init.begin(), init.end(), max(0, n - 15));
	last = init;

	SegmentTree<ll> st;
	if (n > 15) {
		st = SegmentTree<ll>(a, n - 15, 0, [&] (ll x, ll y) {
			return x + y;
		});
	}

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int l, r;
			cin >> l >> r; --l; --r;

			ll ans = 0;
			if (n <= 15) {
				for (int i = l; i <= r; i++) {
					ans += last[i];
				}
			} else {
				if (l < n - 15) {
					ans += st.query(l, min(r, n - 16));
				}
				if (r >= n - 15) {
					for (int i = max(0, l - (n - 15)); i <= r - (n - 15); i++) {
						ans += last[i];
					}
				}
			}
			cout << ans + r - l + 1 << '\n';
		} else {
			int x;
			cin >> x;
			ll carry = x;
			for (int i = 0; i < perm.size(); i++) {
				perm[i] += carry;
				carry = perm[i] / (i + 1);
				perm[i] %= (i + 1);
			}
			vector<int> temp = init;
			for (int i = (int)last.size() - 1; i >= 0; i--) {
				last[i] = temp[perm[i]];
				temp.erase(temp.begin() + perm[i]);
			}
			reverse(last.begin(), last.end());
		}
	}
	return 0;
}