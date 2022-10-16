#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int n, int k, int mod) {
	int ans = 1;
	while (k) {
		if (k % 2) ans = (ans*n) % mod;
		k /= 2; n = (n*n) % mod;
	}
	return ans;
}

const int M = 1e9+7;

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

const int MAX = 500005;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	DSU d(m+1);
	vector<int> ans2;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		if (k == 1) {
			int x; cin >> x;
			if (!d.same(0, x)) {
				ans2.push_back(i);
				d.merge(0, x);
			}
		} else {
			int x, y; cin >> x >> y;
			if (!d.same(x, y)) {
				ans2.push_back(i);
				d.merge(x, y);
			}
		}
	}

	int ans1 = modpow(2, ans2.size(), M);
	cout << ans1 << ' ' << ans2.size() << '\n';
	for (int i: ans2) cout << i << ' ';

	return 0;
}