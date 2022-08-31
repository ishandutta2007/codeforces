#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e6+10, MOD = 998244353;
const int L = 20;

int nck_mod_2(int n, int k) {
    // k subset of n
    return (k & n) == k;
}

/*
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

hash_map<ll, int> mp;
int choose(int n, int k) {
    ll key = (long long) n * N + k;
    if (k < 0) return 0;
    if (mp.find(key) != mp.end()) return mp[key];
    return mp[key] = nck_mod_2(n, k) ^ choose(n, k-1);
}
*/
void solve() {
    int n, k; cin >> n >> k;
    k = n - 1 - k; // at most k powers
    vector<bool> ans(1 << L);
    vector<int> a(n); for (auto& x : a) cin >> x;

    vector<vector<int>> dp(L + 3, vector<int>(n));
    for (int _len = 0; _len < sz(dp); _len++) {
        int len = n - 1 - _len;
        if (len < 0) continue;
        for (int k = 0; k <= len; k++) {
            dp[_len][k] = nck_mod_2(len, k);
            if (k) dp[_len][k] ^= dp[_len][k-1];
        }
    }

    auto choose = [&](int c_n, int c_k) {
        // n - 1 - x = c_n
        return dp[n - 1 - c_n][c_k];
    };

    for (int l = 0; l < n; l++) {
        // dp[r - l]
        ll c = -1;
        for (int r = l; r < n && r - l <= k; r++) {
            // (2 ^ c) ^ (2 ^ x)
            // c * (2 ^ x)
            if (r == l) c = a[r];
            else {
                if (a[r] >= L) break;
                c *= 1LL << a[r];
            }
            if (c >= sz(ans)) break;
            int cur_adj = n - 1 - (r - l);
            if (l) cur_adj--;
            if (r < n-1) cur_adj--;
            bool use = choose(cur_adj, min(k - (r - l), cur_adj));
            if (use) {
                ans[c] = ans[c] ^ 1;
            }
        }
    }

    int last = 0;
    for (int i = 0; i < sz(ans); i++) if (ans[i]) {
        last = i;
    }
    for (int i = last; i >= 0; i--) cout << ans[i];
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}