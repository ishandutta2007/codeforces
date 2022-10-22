#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
int add(int a, int b, int n) {
	a += b;
	if (a >= n) a -= n;
	return a;
}
int sub(int a, int b, int n) {
	a -= b;
	if (a < 0) a += n;
	return a;
}
struct Fenwick {
	int n; 
	vector <int> t;
	Fenwick(int n) : n(n) {
		t.resize(n);
	}
	void add2(int r, int ad) {
		for (int i = r; i < n; i |= (i + 1))
			t[i] += ad;
	}
	void add(int l, int r) {
		add2(l, 1);
		add2(r + 1, -1);
	}
	int get(int r) {
		int res = 0;
		for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
			res += t[i];
		return res;
	}
};
struct SparseTable {
	int n;
	vector <vector <int>> st;
	vector <int> lg;
	SparseTable(vector <int> a) {
		int n = a.size(), log = 1;
		while ((1 << log) < n) log++;
		log++;
		st.resize(log, vector <int>(n));
		for (int i = 0; i < n; ++i)
			st[0][i] = a[i];
		for (int j = 1; j < log; ++j) {
			for (int i = 0; i + (1 << (j - 1))< n; ++i) {
				int v1 = st[j - 1][i];
				int v2 = st[j - 1][i + (1 << (j - 1))];
				st[j][i] = min(v1, v2);
			}
		}
		lg.resize(n + 1);
		for (int i = 2; i <= n; ++i)
			lg[i] = lg[i / 2] + 1;
	}
	int get(int l, int r) {
		int p = lg[r - l + 1];
		int v1 = st[p][l], v2 = st[p][r - (1 << p) + 1];
		return min(v1, v2);
	}
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string s; cin >> s;
	int need; cin >> need;
	int n = s.size();
	vector <int> a;
	for (auto& x : s) a.push_back(x - 'a' + 1);
	a.push_back(0);
	n++;
	vector <int> p(n), c(n), start(max(n, 27ll)), cnt(max(n, 27ll));
	for (auto& x : a) {
		cnt[x]++;
	}
	for (int i = 1; i < start.size(); ++i) {
		start[i] = start[i - 1] + cnt[i - 1];
	}
	for (int i = 0; i < n; ++i) {
		p[start[a[i]]++] = i;
	}
	int ce = 0;
	for (int i = 1; i < n; ++i) {
		if (a[p[i]] != a[p[i - 1]]) ce++;
		c[p[i]] = ce;
	}
	for (int len = 1; len < n; len <<= 1) {
		for (auto& x : cnt) x = 0;
		for (int i = 0; i < n; ++i) {
			p[i] = sub(p[i], len, n);
			cnt[c[p[i]]]++;
		}
		start[0] = 0;
		for (int i = 1; i < n; ++i) {
			start[i] = start[i - 1] + cnt[i - 1];
		}
		vector <int> np(n), nc(n);
		for (int i = 0; i < n; ++i) {
			np[start[c[p[i]]]++] = p[i];
		}
		int ce = 0;
		for (int i = 1; i < n; ++i) {
			if (make_pair(c[np[i]], c[add(np[i], len, n)]) !=
				make_pair(c[np[i - 1]], c[add(np[i - 1], len, n)])) {
				ce++;
			}
			nc[np[i]] = ce;
		}
		p = np, c = nc;
	}
	vector <int> lcp(n), pos(n);
	for (int i = 0; i < n; ++i) {
		pos[p[i]] = i;
	}
	int k = 0;
	for (int i = 0; i < n - 1; ++i) {
		while (i + k < n and p[pos[i] - 1] + k < n and s[i + k] == s[p[pos[i] - 1] + k]) {
			k++;
		}
		lcp[pos[i]] = k;
		k = max(0ll, k - 1);
	}
	if (need > n * (n - 1) / 2) {
		cout << "No such line.\n";
	}
	else {
		SparseTable ST(lcp);
		Fenwick tree(n + 1);
		int cur = 0;
		for (int i = 1; i < n; ++i) {
			int cc = tree.get(i);
			for (int j = p[i] + tree.get(i); j < n - 1; ++j) {
				cc++;
				int l = i, r = n;
				while (l + 1 < r) {
					int m = (l + r) / 2;
					if (ST.get(i + 1, m) >= cc) l = m;
					else r = m;
				}
				if (l - i + 1 + cur >= need) {
					for (int f = p[i]; f <= j; ++f) cout << s[f];
					return 0;
				}
				cur += l - i + 1;
				tree.add(i, l);
			}
		}
	}
}