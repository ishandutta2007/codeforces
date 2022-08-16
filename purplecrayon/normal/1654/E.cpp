#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

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

int n, a[MAXN];

// difference is small, directly check
// common difference is big, answer is small
//      - brute force the start and end index; end index is <= start + SQRT

const int N = 1e5, B = 230;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int d = -B; d <= B; d++) {
        hash_map<int, int> cnt;
        for (int i = 0; i < n; i++) ans = max(ans, ++cnt[a[i] - i * d]);
    }
    for (int i = 0; i < n; i++) {
        const int M = N / B + 3;
        hash_map<int, int> cnt;
        for (int j = i + 1; j < min(n, i + M); j++) {
            int d = a[j] - a[i];
            if (d % (j - i)) continue;
            d /= j - i;

            ans = max(ans, 1 + (++cnt[d]));
        }
    }
    cout << n - ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}