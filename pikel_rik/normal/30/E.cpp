#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

vector<int> suffixArray(string s) {
    s += char(0);
    int n = s.length();
    vector<int> sa(n);
    vector<int> c(n), cnt(max(256, n));
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < 256; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        sa[--cnt[s[i]]] = i;
    }
    c[sa[0]] = 0;
    int classes = 1;

    for (int i = 1; i < n; i++) {
        if (s[sa[i]] != s[sa[i - 1]])
            classes++;
        c[sa[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; h++) {
        for (int i = 0; i < n; i++) {
            pn[i] = (sa[i] + n - (1 << h)) % n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            sa[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[sa[0]] = 0;
        classes = 1;

        for (int i = 1; i < n; i++) {
            if (c[sa[i]] != c[sa[i - 1]] or c[(sa[i] + (1 << h)) % n] != c[(sa[i - 1] + (1 << h)) % n]) {
                classes++;
            }
            cn[sa[i]] = classes - 1;
        }
        c.swap(cn);
    }
    sa.erase(sa.begin());
    return sa;
}

vector<int> LCP(const string& s, const vector<int>& sa) {
    int n = s.length();
    vector<int> lcp(n - 1), rank(n);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k) {
            k--;
        }
    }
    return lcp;
}

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

int n;
string s;
vector<int> sa, lcp, l, r, stk, d;
SparseTable<int> st, dd;

void init() {
	s += char(1);
	for (int i = n - 1; i >= 0; i--) {
		s += s[i];
	}
	sa = suffixArray(s);
	lcp = LCP(s, sa);
	l.assign(lcp.size(), -1);
	r.assign(lcp.size(), lcp.size());
	for (int i = 0; i < lcp.size(); i++) {
		while (!stk.empty() and lcp[stk.back()] >= lcp[i]) {
			stk.pop_back();
		}
		if (!stk.empty()) {
			l[i] = stk.back();
		}
		stk.push_back(i);
	}
	stk.clear();
	for (int i = (int)lcp.size() - 1; i >= 0; i--) {
		while (!stk.empty() and lcp[stk.back()] >= lcp[i]) {
			stk.pop_back();
		}
		if (!stk.empty()) {
			r[i] = stk.back();
		}
		stk.push_back(i);
	}
	d.resize(n);
	for (int i = 0, ll = 0, rr = -1; i < n; i++) {
		int k = (i > rr) ? 1 : min(d[ll + rr - i], rr - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d[i] = k--;
		if (i + k > rr) {
			ll = i - k;
			rr = i + k;
		}
	}
	st = SparseTable<int>(sa, sa.size(), [&] (int x, int y) {
		return x > y ? x : y;
	});
	dd = SparseTable<int>(d, d.size(), [&] (int x, int y) {
		return x > y ? x : y;
	});
}

int binarySearch(int ll, int rr) {
	int lo = 1, hi = rr - ll + 1;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (ll + mid - 1 <= rr - mid + 1 && dd.query(ll + mid - 1, rr - mid + 1) >= mid) {
			lo = mid;
		} else hi = mid - 1;
	}
	return 2 * lo - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	n = s.length();
	init();

	int best = 0;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (best < 2 * d[i] - 1) {
			ans.clear();
			best = 2 * d[i] - 1;
			ans.emplace_back(i - d[i] + 1, 2 * d[i] - 1);
		}
	}

	for (int i = 0; i < lcp.size(); i++) {
		if (sa[i] < n and lcp[i] == n - sa[i]) {
			int j = 2 * n - st.query(l[i] + 1, r[i]);
			if (j < sa[i] - 1) {
				int mid_length = binarySearch(j + 1, sa[i] - 1);
				if (best < 2 * lcp[i] + mid_length) {
					best = 2 * lcp[i] + mid_length;
					ans.clear();
					ans.emplace_back(j - lcp[i] + 1, lcp[i]);
					ans.emplace_back(-1, mid_length);
					ans.emplace_back(sa[i], lcp[i]);
				}
			}
		}
		if (sa[i + 1] < n and lcp[i] == n - sa[i + 1]) {
			int j = 2 * n - st.query(l[i] + 1, r[i]);
			if (j < sa[i + 1] - 1) {
				int mid_length = binarySearch(j + 1, sa[i + 1] - 1);
				if (best < 2 * lcp[i] + mid_length) {
					best = 2 * lcp[i] + mid_length;
					ans.clear();
					ans.emplace_back(j - lcp[i] + 1, lcp[i]);
					ans.emplace_back(-1, mid_length);
					ans.emplace_back(sa[i + 1], lcp[i]);
				}
			}
		}
	}

	if (ans.size() == 3) {
		for (int i = ans[0].first + ans[0].second; i < ans[2].first; i++) {
			int ll = max(i - d[i] + 1, ans[0].first + ans[0].second);
			int rr = min(i + d[i] - 1, ans[2].first -  1);
			if (i - ll > rr - i) {
				ll = 2 * i - rr;
			} else if (i - ll < rr - i) {
				rr = 2 * i - ll;
			}
			if (rr - ll + 1 == ans[1].second) {
				ans[1].first = ll;
				break;
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto& [x, l] : ans) {
		cout << x + 1 << ' ' << l << '\n';
	}
	return 0;
}