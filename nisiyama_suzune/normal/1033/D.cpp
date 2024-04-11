#include <bits/stdc++.h>

namespace NT {
	typedef uint32_t l;
	typedef uint64_t ll;
    inline ll mul (ll const &a, ll const &b, ll const &mod) {
        ll ret = a * (ll) b - (ll) ((long double) a * b / mod - 1.1) * mod;
		if (-ret < ret) ret = mod - 1 - (-ret - 1) % mod;
		else ret %= mod;
		return ret; }
    inline ll pow (ll const &a, ll const &b, ll const &mod) {
        ll ret = 1, base = a;
        for (l i = 0; b >> i; ++i) {
            if ((b >> i) & 1) ret = mul (ret, base, mod);
            base = mul (base, base, mod); }
        return ret; }
    bool miller_rabin_single (ll const &x, ll base) {
        if (x < 4) return x > 1;
        if (x % 2 == 0) return false;
        if ((base %= x) == 0) return true;
        ll xm1 = x - 1; l j = (l) __builtin_ctzl (xm1);
		ll t = pow (base, xm1 >> j, x);
        if (t == 1 || t == xm1) return true;
        for (l k = 1; k < j; ++k) {
            t = mul (t, t, x);
            if (t == xm1) return true;
            if (t <= 1) break; }
        return false; }
    bool miller_rabin_multi (ll const &) { return true; }
    template <typename... S>
    bool miller_rabin_multi (ll const &x, ll const &base, S const &...bases) {
        if (!miller_rabin_single (x, base)) return false;
        return miller_rabin_multi (x, bases...); }
    bool miller_rabin (ll const &x) {
        if(x < 316349281) return miller_rabin_multi (x, 11000544, 31481107);
        if(x < 4759123141ull) return miller_rabin_multi (x, 2, 7, 61);
        return miller_rabin_multi (x, 2, 325, 9375, 28178, 450775, 9780504, 1795265022); }
    ll isqrt (ll const &x){
        ll ret = static_cast <ll> (sqrtl (x));
        while (ret > 0 && ret * ret > x) --ret;
        while (x - ret * ret > 2 * ret) ++ret;
        return ret; }
    ll icbrt (ll const &x) {
        ll ret = static_cast <ll> (cbrt (x));
        while (ret > 0 && ret * ret * ret > x) --ret;
        while (x - ret * ret * ret > 3 * ret * (ret + 1)) ++ret;
        return ret; }
    std::vector <l> saved;
    ll squfof_iter_better (ll const &x, ll const &k, ll const &it_max, l cutoff_div) {
        if(std::__gcd ((ll) k, x) != 1) return std::__gcd ((ll) k, x);
        saved.clear (); ll scaledn = k * x;
        if (scaledn >> 62) return 1;
        l sqrtn = isqrt (scaledn), cutoff = isqrt (2 * sqrtn) / cutoff_div;
        l q0 = 1, p1 = sqrtn, q1 = scaledn - p1 * p1;
        if (q1 == 0) { ll factor = std::__gcd (x, (ll) p1); return factor == x ? 1 : factor; }
        l multiplier = 2 * k, coarse_cutoff = cutoff * multiplier;
        l i, j, p0 = 0, sqrtq = 0;
        for (i = 0; i < it_max; ++i) {
            l q = 1, bits, tmp = sqrtn + p1 - q1;
            if (tmp >= q1) q += tmp / q1;
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
            if (q1 < coarse_cutoff) {
                tmp = q1 / std::__gcd (q1, multiplier);
                if (tmp < cutoff) saved.push_back ((l) tmp); }
            bits = 0; tmp = q0;
            while (!(tmp & 1)) { bits++; tmp >>= 1; }
            if (!(bits & 1) && ((tmp & 7) == 1)) {
                sqrtq = (l) isqrt (q0);
                if (sqrtq * sqrtq == q0) {
                    for (j = 0; j < saved.size (); ++j)
                        if (saved[j] == sqrtq) break;
                    if (j == saved.size ()) break; } }
            tmp = sqrtn + p0 - q0; q = 1;
            if (tmp >= q0) q += tmp / q0;
            p1 = q * q0 - p0; q1 = q1 + (p0 - p1) * q;
            if (q0 < coarse_cutoff) {
                tmp = q0 / std::__gcd (q0, multiplier);
                if (tmp < cutoff) saved.push_back ((l) tmp); } }
        if (sqrtq == 1 || i == it_max) return 1;
        q0 = sqrtq; p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (ll) p1 * (ll) p1) / (ll) q0;
        for (j = 0; j < it_max; ++j) {
            l q = 1, tmp = sqrtn + p1 - q1;
            if (tmp >= q1) q += tmp / q1;
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
            if (p0 == p1) { q0 = q1; break; }
			q = 1; tmp = sqrtn + p0 - q0;
            if (tmp >= q0) q += tmp / q0;
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
            if (p0 == p1) break; }
        if (j == it_max) { std::cout << "RNG\n"; assert (0); return 1; } // Random failure.
        ll factor = std::__gcd ((ll) q0, x);
        if (factor == x) factor = 1;
        return factor; }
    ll squfof (ll const &x) {
        static std::array <l, 16> multipliers { 1, 3, 5, 7, 11, 15, 21, 33, 35, 55, 77, 105, 165, 231, 385, 1155 };
        ll cbrt_x = icbrt (x);
        if (cbrt_x * cbrt_x * cbrt_x == x) return cbrt_x;
        l iter_lim = 300;
        for (l iter_fact = 1; iter_fact < 20000; iter_fact *= 4) {
            for (l const &k : multipliers) {
                if (std::numeric_limits<ll>::max () / k <= x) continue;
             	l const it_max = iter_fact * iter_lim;
                ll factor = squfof_iter_better (x, k, it_max, 1);
                if (factor == 1 || factor == x) continue;
                return factor; } }
        std::cout << "Failed to factor: " << x << "\n";
        assert(0); return 1; }
    std::vector <ll> factorize (ll x){
        std::vector <ll> ret;
        const l trial_limit = 5000;
		auto trial = [&] (l const &i) { while (x % i == 0) { x /= i; ret.push_back (i); } };
		trial (2); trial (3);
        for (l i = 5, j = 2; i < trial_limit && i * i <= x; i += j, j = 6 - j) trial(i);
        if (x > 1) {
            static std::stack <ll> s; s.push (x);
            while (!s.empty ()) {
                x = s.top (); s.pop ();
                if (!miller_rabin (x)) {
                    ll factor = squfof (x);
                    if (factor == 1 || factor == x) { assert(0); return ret; }
                    s.push (factor); s.push (x / factor);
				} else ret.push_back(x); } }
		std::sort (ret.begin (), ret.end ()); return ret; } }

using ll = long long;
constexpr ll mod = 998244353;
std::unordered_map <ll, ll> mp;
int main () {
	std::cin.tie (0);
    std::ios_base::sync_with_stdio (false);
    ll i,j,k,n,m,x;
    std::cin >> n;
    ll ans = 1;
    for (i = 1; i <= n; i++) {
        std::cin >> x;
		auto tmp = NT::factorize (x);
		for (auto &e : tmp) ++mp[e];
    }
    for (auto x : mp) ans = ans * (x.second + 1) % mod;
    std::cout << ans << '\n';
    return 0;
}