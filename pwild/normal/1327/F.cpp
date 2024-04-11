#include <bits/stdc++.h>
using namespace std;

#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define eb emplace_back

const int MOD = 998244353;

template<typename T>
struct segtree {
	int n;
	vector<T> value;

	segtree<T>(vector<T> leaves): n(leaves.size()) {
		value.resize(2*n);
		copy(all(leaves),begin(value)+n);
		FORD(i,1,n) value[i] = value[2*i] + value[2*i+1];
	}
	
	void update(int i, T v) {
		i += n;
		value[i] = v;
		for (i /= 2; i; i /= 2) value[i] = value[2*i] + value[2*i+1];
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

struct node {
	int x = 0;
	node operator+(node n) { return {(x+n.x) % MOD}; }
};

int solve(int n, const vector<pair<int,int>> &none, const vector<pair<int,int>> &some) {
	vector<int> jump(n+1,n+1);
	
	for (auto [a,b]: some) {
		jump[a] = min(jump[a], b);
	}
	FORD(i,0,n) jump[i] = min(jump[i], jump[i+1]);

	vector<int> depth(n+1);
	for (auto [a,b]: none) {
		depth[a]++, depth[b]--;
	}
	
	FOR(i,0,n) depth[i+1] += depth[i];
	
	vector<long long> sum(n+2);
	sum[n] = 1;

	FORD(i,0,n) {
		sum[i] = sum[i+1];
		if (depth[i] == 0) {
			long cur = sum[i+1] - sum[ jump[i+1] ];
			sum[i] = (sum[i] + cur) % MOD;
		}
	}

	long res = (sum[0] - sum[ jump[0] ]) % MOD;
	if (res < 0) res += MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, K, m;
	cin >> n >> K >> m;
	
	vector<int> a(m), b(m), x(m);
	FOR(i,0,m) {
		cin >> a[i] >> b[i] >> x[i];
		a[i]--;
	}
	
	long long res = 1;
	FOR(k,0,K) {
		vector<pair<int,int>> none, some;
		FOR(i,0,m) {
			((x[i] & (1 << k)) ? none : some).eb(a[i],b[i]);
		}
		res = res * 1LL * solve(n, none, some) % MOD;
	}
	cout << res << endl;
}