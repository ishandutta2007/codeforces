#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;

#include<bits/extc++.h>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
vector<ll> pf(ll n) {
    vector<ll> ans;
    for (ll x = 2; x * x <= n; x++) if (n % x == 0) {
        ans.push_back(x);
        while (n % x == 0) n /= x;
    }
    if (n > 1) ans.push_back(n);
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;

    double clock_begin = clock();

    auto cur_time = [&]() -> double {
        return (clock() - clock_begin) / CLOCKS_PER_SEC;
    };

    ll ans = 1;
    for (int rep = 0; rep < 11; rep++) {
#ifndef LOCAL
        if (cur_time() >= 3.8) break;
#endif
        hash_map<ll, int> dp;

        int c = rnd(0, n-1);
        for (auto& x : a) dp[gcd(x, a[c])]++;

        vector<ll> one, two;
        for (ll x = 1; x * x <= a[c]; x++) if (a[c] % x == 0) {
            one.push_back(x);
            if (x * x < a[c]) two.push_back(a[c] / x);
        }
        reverse(two.begin(), two.end());

        vector<ll> factors;
        for (ll x : one) factors.push_back(x);
        for (ll x : two) factors.push_back(x);
        assert(std::is_sorted(factors.begin(), factors.end()));

        auto primes = pf(a[c]);
        for (ll p : primes) {
            for (int i = sz(factors)-1; i >= 0; i--) {
                dp[factors[i]] += dp[factors[i] * p];
            }
        }
        for (auto& [x, k] : dp) if (k >= (n + 1) / 2) {
            ans = max(ans, x);
        }
    }
    cout << ans << '\n';
#ifdef LOCAL
    cerr << cur_time() << endl;
#endif
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}