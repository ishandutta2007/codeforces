#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int n, p, ans, fac[5005], inv_fac[5005];

int nck(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] % p * inv_fac[n - k] % p;
}

int exp_p(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % p;
		a = a * a % p;
		b >>= 1ll;
	}
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	fac[0] = inv_fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % p;
		inv_fac[i] = exp_p(fac[i], p - 2);
	}
	int gap = n / 2;
	for (int len = 1; len <= gap - (n % 2 == 0); len++) {
		
		int lo = len + 2, hi = n, l = -1, r = -1;
		
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (mid - (len + 1) <= gap && n - mid + 1 <= gap) l = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		
		lo = gap + 2, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (mid - (len + 1) <= gap && n - mid + 1 <= gap) r = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		
		assert(l != -1 && r != -1);
		
		int cur = 0;
		
		for (int x = 0; x <= n; x++) {
			if (n - 2 - x - 1 >= 0) cur += nck(len - 1, x) * (r - l + 1) % p * fac[n - 2 - x - 1] % p;
			cur %= p;
		}
		
		//~ cout << len << ' ' << cur << '\n';
		
		ans += n * cur % p;
		ans %= p;
	}
	if (n % 2 == 0) {
		ans += n * fac[n - 2] % p;
		ans %= p;
	}
	cout << ans << '\n';
}