#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define P2(n) (1ll << (n))

struct Query
{
	char q;
	ll a;
	ll b;
};

int gf(vector<int>& f, int cur) {
	int root = cur;
	while (f[root] >= 0) {
		root = f[root];
	}
	int next = f[cur];
	while (next >= 0) {
		f[cur] = root;
		cur = next;
		next = f[cur];
	}
	return root;
}
void mf(vector<int>& f, int a, int b) {
	a = gf(f, a);
	b = gf(f, b);
	if (a == b) {
		return;
	}
	f[a] = b;
}

int is_pow2(ll n) {
	return (n & (n - 1)) == 0;
}

int main()
{
#ifdef _MSC_VER
	// freopen("g.in", "r", stdin);
	freopen("g-large.in", "r", stdin);
	double start_time = (double)clock();
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<Query> q(m);
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s >> q[i].a >> q[i].b;
		q[i].q = s[0];
	}
	
	set<ll> pts;
	pts.insert(0);
	pts.insert(P2(n));
	for (int i = 0; i < m; ++i) {
		if (q[i].q == 'b') {
			ll a = q[i].a;
			ll b = q[i].b + 1;
			pts.insert(a);
			pts.insert(b);
		}
	}
	vector<ll> pre_vals(pts.begin(), pts.end());
	for (int i = 0; i + 1 < pre_vals.size(); ++i) {
		ll a = pre_vals[i];
		ll b = pre_vals[i + 1];
		while (a < b) {
			for (int i = n - 1; i >= 0; --i) {
				if ((a & (P2(i) - 1)) == 0 && a + P2(i) <= b) {
					a += P2(i);
					pts.insert(a);
					break;
				}
			}
		}
	}
	vector<int> ret(m);
	vector<ll> vals(pts.begin(), pts.end());
	vector<int> f(vals.size(), -1);

#ifdef _MSC_VER
	printf("#vals = %d\n", (int)vals.size());
#endif

	vector<int> ok(vals.size());
	vector<int> bad(vals.size());
	for (int i = m - 1; i >= 0; --i) {
		if (q[i].q == 'b') {
			ll a = q[i].a;
			ll b = q[i].b + 1;
			int idx = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
			for (; idx < vals.size() && vals[idx] < b; ++idx) {
				bad[idx] = 1;
			}
		}
	}

	int total = 0;
	vector<int> logw(vals.size());
	for (int i = 0; i + 1 < vals.size(); ++i) {
		ll w = vals[i + 1] - vals[i];
		int b = 0;
		while (w != 1) {
			++b;
			w >>= 1;
		}
		logw[i] = b;
	}

	auto recover = [&](int idx) {
		assert(!ok[idx]);
		ok[idx] = 1;
		ll cur = vals[idx];
		int l_idx = logw[idx];
		for (int bit = l_idx; bit < n; ++bit) {
			ll next = (cur ^ P2(bit));
			int i = upper_bound(vals.begin(), vals.end(), next) - vals.begin() - 1;
			for (; i + 1 < vals.size(); ++i) {
				int l_i = logw[i];
				ll diff = ((vals[idx] ^ vals[i]) >> max(l_idx, l_i));
				if (!is_pow2(diff)) {
					break;
				}
				if (ok[i]) {
					++total;
					mf(f, idx, i);
				}
			}
		}
	};
#ifdef _MSC_VER
	printf("#start\n");
#endif
	for (int i = 0; i + 1 < vals.size(); ++i) {
		if (!bad[i]) {
			recover(i);
		}
	}
#ifdef _MSC_VER
	printf("#recover-not-bad  #total = %d   time = %.3lf\n", total, ((double)clock() - start_time) / CLOCKS_PER_SEC);
#endif
	for (int i = m - 1; i >= 0; --i) {
		if (q[i].q == 'b') {
			ll a = q[i].a;
			ll b = q[i].b + 1;
			int idx = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
			for (; idx < vals.size() && vals[idx] < b; ++idx) {
				recover(idx);
			}
		} else {
			ll a = q[i].a;
			ll b = q[i].b;
			int idx_a = upper_bound(vals.begin(), vals.end(), a) - vals.begin() - 1;
			int idx_b = upper_bound(vals.begin(), vals.end(), b) - vals.begin() - 1;
			assert(ok[idx_a]);
			assert(ok[idx_b]);
			ret[i] = (gf(f, idx_a) == gf(f, idx_b) ? 1 : 0);
		}
	}
#ifdef _MSC_VER
	printf("#recover-all      #total = %d   time = %.3lf\n", total, ((double)clock() - start_time) / CLOCKS_PER_SEC);
#endif
	for (int i = 0; i < m; ++i) {
		if (q[i].q == 'a') {
			printf("%d\n", ret[i]);
		}
	}
	return 0;
}