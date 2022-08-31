#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

const int N = 3000 + 5;

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

int n, a[N], d[N], ans[N], ind[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(ans, -1, sizeof(ans));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	iota(ind, ind + n, 0);
	sort(ind, ind + n, [&] (int i, int j) {
		return a[i] < a[j];
	});

	d[0] = a[ind[0]];
	for (int i = 1; i < n; i++) {
		d[i] = a[ind[i]] - a[ind[i - 1]];
	}

	vector<int> temp(n);
	iota(temp.begin(), temp.end(), 0);
	SparseTable<int> st(temp, n, [&] (int x, int y) {
		return d[x] > d[y] ? x : y;
	});

	int best1 = -1, best2 = -1, best3 = -1;
	int d1 = -1, d2 = -1, d3 = -1;
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < i; j++) {
			if (n - i > 2 * (i - j) or i - j > 2 * (n - i)) continue;
			if (2 * j < n - i or 2 * j < i - j) continue;

			int l = (max(n - i, i - j) + 1) / 2, r = 2 * min(n - i, i - j);
			r = min(r, j);

			int k = st.query(j - r, j - l);
			if (d[i] > best1) {
				best1 = d[i];
				best2 = d[j];
				best3 = d[k];
				d1 = i, d2 = j, d3 = k;
			} else if (d[i] == best1 and d[j] > best2) {
				best2 = d[j];
				best3 = d[k];
				d1 = i, d2 = j, d3 = k;
			} else if (d[i] == best1 and d[j] == best2 and d[k] > best3) {
				best3 = d[k];
				d1 = i, d2 = j, d3 = k;
			}
		}
	}

	for (int i = d1; i < n; i++) {
		ans[ind[i]] = 1;
	}
	for (int i = d2; i < d1; i++) {
		ans[ind[i]] = 2;
	}
	for (int i = d3; i < d2; i++) {
		ans[ind[i]] = 3;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i + 1 == n];
	}
	return 0;
}