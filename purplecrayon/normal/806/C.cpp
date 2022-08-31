#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

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
void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;

    auto v = [&](int m) -> bool {
        //build m sequences
        hash_map<ll, int> s;
        for (auto c : a) s[c]++;

        vector<ll> last;
        for (int rep = 0; rep < m; rep++) {
            if (!s[1]) return 0; 
            ll c = 1;
            while (s[c]) {
                s[c]--;
                c *= 2;
            }
            last.push_back(c);
        }

        vector<ll> have;
        for (auto c : s) {
            while (c.second--) have.push_back(c.first);
        }
        while (sz(have) < sz(last)) have.push_back(0);
        if (sz(have) > sz(last)) return 0;

        sort(have.begin(), have.end());
        sort(last.begin(), last.end());

        for (int i = 0; i < sz(last); i++) if (have[i] > last[i]) return 0;
        return 1;
    };

    int cnt_ones = std::count(a.begin(), a.end(), 1ll);
    if (!v(cnt_ones)){ cout << -1 << '\n'; return; }
    int lo = 0, hi = cnt_ones, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    for (int i = hi; i <= cnt_ones; i++) cout << i << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}



//A: 7m 23s
//