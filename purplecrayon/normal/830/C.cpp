#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n;
ll k, a[MAXN];

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
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], k += a[i];
    hash_set<ll> imp;
    for (int i = 0; i < n; i++) {
        for (ll x = 1; x*x <= a[i]; x++) {
            imp.insert(x);
            imp.insert((a[i]+x-1)/x);
        }
        imp.insert(a[i]+1);
    }
    imp.insert(INF);
    vector<ll> v(imp.begin(), imp.end());
    sort(v.begin(), v.end());


    ll ans = 1;
    for (int i = 0; i < sz(v)-1; i++) {
        ll l = v[i], r = v[i+1] - 1;
        ll sm = 0;
        for (int j = 0; j < n; j++) sm += (a[j]+l-1)/l;
        //maximum value x such that x*sum <= k
        //x == floor(k/sum)

        ll x = k/sm;
        if (x >= l) ans = max(ans, min(x, r));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}