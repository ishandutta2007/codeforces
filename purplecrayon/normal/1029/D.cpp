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

int n, k, a[MAXN];
hash_map<int, int> cnt[11];

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) {
        for (int i = 0, c = a[j]%k; i <= 10; i++, c = ll(c)*10%k) {
            cnt[i][c]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int len = 0, c = a[i];
        while (c) c /= 10, len++;

        int other = (k-(a[i]%k))%k;

        ll me = a[i];
        for (int rep = 0; rep < len; rep++) me *= 10, me %= k;
        if ((me+a[i])%k == 0) ans--;

        ans += cnt[len][other];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}