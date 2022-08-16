#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;
const int B = 15;

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

int n, a[MAXN];
int one[MAXN], two[MAXN];
map<pair<ll, ll>, int> mp;

pair<ll, ll> hash_vector(vector<int> c) {
    const int SHIFT = 40;
    assert(*min_element(c.begin(), c.end()) > -SHIFT);
    assert(*max_element(c.begin(), c.end()) < SHIFT);
    for (auto& x : c) x += SHIFT;

    const int M1 = 1e9+9, M2 = 1e9+21;

    const int BASE = 83;
    ll h1 = 0, h2 = 0;
    for (auto& x : c) {
        h1 = h1*BASE%M1;
        h1 = (h1+x)%M1;

        h2 = h2*BASE%M2;
        h2 = (h2+x)%M2;
    }
    return make_pair(h1, h2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        one[i] = a[i] & ((1 << B) - 1);
        two[i] = a[i] >> B;
    }
    for (int i = 0; i < (1<<B); i++) {
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            b[j] = __builtin_popcount(one[j] ^ i);
            if (j) b[j] -= b[0];
        }
        b[0] = 0;

        for (auto& c : b) c *= -1;
        mp[hash_vector(b)] = i;
    }
    for (int i = 0; i < (1<<B); i++) {
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            b[j] = __builtin_popcount(two[j] ^ i);
            if (j) b[j] -= b[0];
        }
        b[0] = 0;

        auto h = hash_vector(b);
        if (mp.find(h) != mp.end()) {
            int ans = ((i << B) | mp[h]);
            cout << ans << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}