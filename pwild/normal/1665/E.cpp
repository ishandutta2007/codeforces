#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segtree {
	int n;
	vector<T> value;

	segtree(int n): n(n), value(2*n) { }
	
	void init(vector<T> leaves) {
		copy(begin(leaves), end(leaves), begin(value)+n);
		for (int i = n-1; i >= 1; i--) {
			value[i] = value[2*i] + value[2*i+1];
		}
	}
	
	void update(int i, T v) {
		i += n;
		value[i] = v;
		for (i /= 2; i; i /= 2) {
			value[i] = value[2*i] + value[2*i+1];
		}
	}
	
	T query(int i, int j) {
		i += n, j += n;
		T resl, resr;
		for (; i < j; i /= 2, j /= 2) {
			if (i & 1) resl = resl + value[i++];
			if (j & 1) resr = value[--j] + resr;
		}
		return resl + resr;
	}
};

const int K = 32;

struct node {
	vector<int> a;
	node operator+(node n) {
		vector<int> b;
		merge(begin(a), end(a), begin(n.a), end(n.a), back_inserter(b));
		if (ssize(b) > K) b.resize(K);
		return {b};
	}

	int min_or() {
		int res = INT_MAX;
		for (int i = 0; i < ssize(a); i++) {
			for (int j = 0; j < i; j++) {
				res = min(res, a[i]|a[j]);
			}
		}
		return res;
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	segtree<node> S(n);
	vector<node> v(n);
	for (int i = 0; i < n; i++) v[i] = {{a[i]}};
	S.init(v);

	int q; cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << S.query(i-1,j).min_or() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--) solve();
}