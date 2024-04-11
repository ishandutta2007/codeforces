#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int K = 3;
const int eff[K] = { 1, -2, 1 };
int S[K][K];

struct block {
	int dp[K][K];
	block() {
		for (int i = 0; i < K; i++) for (int j = 0; j < K; j++)
			dp[i][j] = -md;
	}
	block(int v) {
		for (int i = 0; i < K; i++) for (int j = i; j < K; j++)
			dp[i][j] = v * S[i][j];
	}
	void push(int val) {
		for (int i = 0; i < K; i++) for (int j = i; j < K; j++)
			dp[i][j] += val * S[i][j];
	}
	block operator * (const block &a) const {
		block rtn;
		for (int i = 0; i < K; i++) for (int j = i; j < K; j++) {
			rtn.dp[i][j] = max(dp[i][j], a.dp[i][j]);
			for (int k = i; k + 1 <= j; k++)
				rtn.dp[i][j] = max(rtn.dp[i][j], dp[i][k] + a.dp[k + 1][j]);
		}
		return rtn;
	}
};

struct segtree {
	int n;
	vector<block> t;
	vector<int> tag;
	segtree() {}
	segtree(const vector<int> &a) {
		n = max(2, (int)a.size());
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n);
		tag.resize(2 * n, 0);
		for (int i = 0; i < a.size(); i++)
			t[i + n - 1] = block(a[i]);
		for (int i = n - 2; i >= 0; i--)
			fix(i);
	}
	void push(int x) {
		if (!tag[x]) return;
		t[x].push(tag[x]);
		if (x < n - 1) {
			tag[x + x + 1] += tag[x];
			tag[x + x + 2] += tag[x];
		}
		tag[x] = 0;
	}
	void fix(int x) {
		push(x + x + 1);
		push(x + x + 2);
		t[x] = t[x + x + 1] * t[x + x + 2];
	}
	void add(int l, int r, int v) {
		add(l, r, v, 0, 0, n - 1);
	}
	void add(int l, int r, int v, int node, int nl, int nr) {
		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			tag[node] += v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		add(l, r, v, 2 * node + 1, nl, mid);
		add(l, r, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, n - 1).dp[0][K - 1];
	}
	block query(int l, int r, int node, int nl, int nr) {
		if (r < nl || nr < l) return block();
		push(node);
		if (l <= nl && nr <= r) return t[node];
		int mid = (nl + nr) / 2;
		return
			query(l, r, 2 * node + 1, nl, mid) *
			query(l, r, 2 * node + 2, mid + 1, nr);
	}
};

int n, q;
string s;
vector<int> dep;
segtree T;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < K; i++) {
		S[i][i] = eff[i];
		for (int j = i + 1; j < K; j++)
			S[i][j] = S[i][j - 1] + eff[j];
	}

	cin >> n >> q >> s;
	dep.push_back(0);
	for (const auto &i : s)
		if (i == '(')
			dep.push_back(dep.back() + 1);
		else
			dep.push_back(dep.back() - 1);
	s.insert(s.begin(), '0');

	T = segtree(dep);
	cout << T.query(0, (int)dep.size() - 1) << '\n';
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l > r) swap(l, r);
		if (s[l] == s[r]) {
			cout << T.query(0, (int)dep.size() - 1) << '\n';
			continue;
		}
		if (s[l] == '(')
			T.add(l, r - 1, -2);
		else
			T.add(l, r - 1, 2);
		swap(s[l], s[r]);
		cout << T.query(0, (int)dep.size() - 1) << '\n';
	}
}