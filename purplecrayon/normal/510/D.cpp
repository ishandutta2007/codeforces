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

vector<pair<int, int>> get_pf_big(int n){
    vector<pair<int, int>> r;
    for (ll i = 2; i*i <= n; i++) if (n%i == 0){
        r.emplace_back(i, 0);
        while (n%i == 0) r.back().second++, n /= i;
    }
    if (n>1) r.emplace_back(n, 1);
    return r;
}

const ll INF = 1e18+10;

const int MAXB = 10;

int n, a[MAXN];
vector<pair<int, int>> pf[MAXN];
ll cost[MAXN], ans = INF;
int b[MAXN];
ll dp[1<<MAXB];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], pf[i] = get_pf_big(a[i]);
    for (int i = 0; i < n; i++) cin >> cost[i];

    for (int i = 0; i < n; i++) {
        hash_map<int, int> c;
        int x = 0;
        for (auto [p, _] : pf[i]) {
            c[p] = x++;
        }
        for (int j = 0; j < n; j++) {
            int mask = 0;
            for (auto [p, _] : pf[j]) if (c.find(p) != c.end()) {
                mask |= 1 << c[p];
            }
            mask ^= (1<<x)-1;
            b[j] = mask;
        }
        for (int i = 0; i < (1<<x); i++) dp[i] = INF;
        dp[0] = cost[i];
        for (int j = 0; j < n; j++) {
            for (int m = 0; m < (1<<x); m++) {
                dp[m|b[j]] = min(dp[m|b[j]], dp[m]+cost[j]);
            }
        }
        ans = min(ans, dp[(1<<x)-1]);
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}