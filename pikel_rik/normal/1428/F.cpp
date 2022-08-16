#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5e5 + 5;

template <typename T>
class SparseTable {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<vector<T>> mat;
    F f;
    SparseTable(): n(), mat(), f() {}

    template <typename U>
    SparseTable(const U& arr, int n, F f): n(n), f(f), mat((int)log2(n) + 1) {
        mat[0].resize(n);
        for (int i = 0; i < n; i++)
            mat[0][i] = T(arr[i]);
        for (int j = 1; j < mat.size(); j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i + (1 << j) <= n; i++) {
                mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T query(int l, int r) {
        int j = 32 - __builtin_clz(r - l + 1) - 1;
        return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
    }
};

int n, pref[N], suf[N];
string s;

ll f(ll x) {
	if (x < 0) {
		return 0;
	}
	return (x + 1) * (x * x + x) / 2 - (x * (x + 1) * (2 * x + 1)) / 6;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;

	pref[0] = s[0] == '1';
	for (int i = 1; i < n; i++) {
		if (s[i] == '0') {
			pref[i] = 0;
		} else {
			pref[i] = 1 + pref[i - 1];
		}
	}

	suf[n - 1] = s[n - 1] == '1';
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == '0') {
			suf[i] = 0;
		} else {
			suf[i] = 1 + suf[i + 1];
		}
	}

	SparseTable<int> pref_table(pref, n, [&] (int x, int y) {
		return x > y ? x : y;
	});

	SparseTable<int> suf_table(suf, n, [&] (int x, int y) {
		return x > y ? x : y;
	});

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') continue;
		if (i + 1 == n or s[i + 1] == '0') {
			ans += f(pref[i] - 2);
		}

		int l, r, j = i - pref[i] + 1;
		int lo = 0, hi = j;

		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (suf_table.query(mid, j - 1) <= pref[i]) {
				hi = mid;
			} else lo = mid + 1;
		}

		l = lo;
		lo = i, hi = n - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (pref_table.query(i + 1, mid) < pref[i]) {
				lo = mid;
			} else hi = mid - 1;
		}

		r = lo;
		ans += (ll)(j - l + 1) * (r - i + 1) * pref[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		if (s[i] == '0' or s[i - 1] == '0') continue;

		int j = i + suf[i] - 1;
		int lo = j, hi = n - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (pref_table.query(j + 1, mid) < suf[i]) {
				lo = mid;
			} else hi = mid - 1;
		}

		ans += (ll)(lo - j + 1) * suf[i];
	}

	cout << ans << '\n';
	return 0;
}