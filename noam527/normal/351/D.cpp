#include <bits/stdc++.h>
#include <unordered_map>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int N = 100005, K = 500;

struct smartass {
	unordered_map<int, int> M;
	smartass() {}
	void insert(int v) {
		M[v]++;
	}
	void erase(int v) {
		if (M[v] == 1) M.erase(v);
		else M[v]--;
	}
	int query() {
		return M.size();
	}
};

struct query {
	int l, r, i;
	query() {}
	query(int L, int R, int I) {
		l = L;
		r = R;
		i = I;
	}
	bool operator < (const query &a) const {
		if (l / K != a.l / K) return l / K < a.l / K;
		return r < a.r;
	}
};

int n, q;
vector<int> a;



vector<query> Q;
vector<int> ans;
vector<int> nxt, lst;
int occ[N];

int L = 0, R = -1;
smartass uniq;
smartass diff[N];
set<int> good;
int cnt[N] = {};

void work(int l, int r) {
	while (l < L) {
		--L;
		int v = a[L];
		uniq.insert(v);
		cnt[v]++;
		if (cnt[v] == 1) {
			good.insert(v);
		}
		else {
			if (diff[v].query() < 2) good.erase(v);
			diff[v].insert(nxt[L]);
			if (diff[v].query() < 2) good.insert(v);
		}
	}
	while (R < r) {
		++R;
		int v = a[R];
		uniq.insert(v);
		cnt[v]++;
		if (cnt[v] == 1) {
			good.insert(v);
		}
		else {
			if (diff[v].query() < 2) good.erase(v);
			diff[v].insert(lst[R]);
			if (diff[v].query() < 2) good.insert(v);
		}
	}

	while (L < l) {
		int v = a[L];
		uniq.erase(v);
		cnt[v]--;
		if (cnt[v] == 0) good.erase(v);
		else {
			if (diff[v].query() < 2) good.erase(v);
			diff[v].erase(nxt[L]);
			if (diff[v].query() < 2) good.insert(v);
		}
		++L;
	}
	while (r < R) {
		int v = a[R];
		uniq.erase(v);
		cnt[v]--;
		if (cnt[v] == 0) good.erase(v);
		else {
			if (diff[v].query() < 2) good.erase(v);
			diff[v].erase(lst[R]);
			if (diff[v].query() < 2) good.insert(v);
		}
		--R;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	cin >> q;
	ans.resize(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		Q.push_back(query(l - 1, r - 1, i));
	}
	sort(Q.begin(), Q.end());

	nxt.resize(n);
	lst.resize(n);
	for (int i = 0; i < N; i++) occ[i] = -1;
	for (int i = 0; i < n; i++) {
		lst[i] = i - occ[a[i]];
		occ[a[i]] = i;
	}
	for (int i = 0; i < N; i++) occ[i] = -1;
	for (int i = n - 1; i >= 0; i--) {
		nxt[i] = occ[a[i]] - i;
		occ[a[i]] = i;
	}

	for (const auto &i : Q) {
		work(i.l, i.r);
		ans[i.i] = uniq.query() + (good.size() ? 0 : 1);
	}
	for (const auto &i : ans) cout << i << '\n';
}