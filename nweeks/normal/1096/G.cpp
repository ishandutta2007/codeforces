#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

namespace ntt {

	static int fast_pow(int x, int y, int z) {
		int64_t ret = 1;
		for (; y; y >>= 1, x = (int64_t)x * x % z) {
			if (y & 1) ret = ret * x % z;
		}
		return ret;
	}

	int revv(int x, int bits) {
		int ret = 0;
		for (int i = 0; i < bits; i++) {
			ret <<= 1, ret |= x & 1, x >>= 1;
		}
		return ret;
	}

	void ntt(std::vector<int> &a, bool rev, int mod, int root) {
		int n = a.size(), bits = 32 - __builtin_clz(n) - 1;
		for (int i = 0; i < n; i++) {
			int j = revv(i, bits);
			if (i < j) std::swap(a[i], a[j]);
		}
		for (int k = 1; k < n; k <<= 1) {
			int e = fast_pow(root, (mod - 1) / 2 / k, mod);
			if (rev) e = fast_pow(e, mod - 2, mod);
			for (int i = 0; i < n; i += 2 * k) {
				int64_t w = 1;
				for (int j = 0; j < k; j++, w = w * e % mod) {
					int x = a[i + j], y = w * a[i + j + k] % mod;
					a[i + j] = (x + y) % mod, a[i + j + k] = (x - y + mod) % mod;
				}
			}
		}
		if (rev) {
			int inv = fast_pow(n, mod - 2, mod);
			for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * inv % mod;
		}
	}

	// const int mod = (119 << 23) + 1, root = 3; // = 998244353
	// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
	// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

	std::vector<int> convolution(const std::vector<int> &a,
			const std::vector<int> &b,
			int mod = (119 << 23) + 1, int root = 3) {
		int sz = (int)a.size() + (int)b.size() - 1;
		int L = sz > 1 ? 32 - __builtin_clz(sz - 1) : 0, n = 1 << L;
		std::vector<int> av(n), bv(n);
		std::copy(a.begin(), a.end(), av.begin());
		std::copy(b.begin(), b.end(), bv.begin());
		ntt(av, false, mod, root), ntt(bv, false, mod, root);
		for (int i = 0; i < n; i++) {
			av[i] = 1LL * av[i] * bv[i] % mod;
		}
		ntt(av, true, mod, root);
		av.resize(sz);
		return av;
	}
}  // namespace ntt

const int MOD = 998244353;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k;
	read2(n,k);
	vi dig(k);
	readv(dig);
	
	vector<int> pol(10);
	FORR(v, dig) pol[v]=1;

	vector<int> ret(1,1);

	int b=n/2;
	while (b)
	{
		if (b%2)
			ret = ntt::convolution(ret, pol);
		b /= 2;
		pol = ntt::convolution(pol,pol);
	}
	ll r(0);
	FORR(v, ret)
		r= (r+ (ll)v*v%MOD)%MOD;
	cout<<r<<endl;
}