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

int n;
ar<int, 2> a[MAXN];
vector<ar<int, 2>> x[MAXN], y[MAXN];
hash_set<ll> hs;

ll get(ar<int, 2> c) {
    return ((long long) c[0] * MAXN) + c[1];
}
bool exists(ar<int, 2> c) {
    return hs.find(get(c)) != hs.end();
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) { 
        cin >> a[i][0] >> a[i][1];
        x[a[i][0]].push_back(a[i]), y[a[i][1]].push_back(a[i]);

        hs.insert(get(a[i]));
    }

    for (int i = 0; i < MAXN; i++) sort(x[i].begin(), x[i].end(), [&](auto a, auto b){ return a[1] < b[1]; });
    for (int i = 0; i < MAXN; i++) sort(y[i].begin(), y[i].end(), [&](auto a, auto b){ return a[0] < b[0]; });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sz(x[a[i][0]]) < sz(y[a[i][1]])) {
            for (auto [x1, y1] : x[a[i][0]]) {
                auto [x2, y2] = a[i];
                if (y2 <= y1) break;
                int d = y2-y1;

                ar<int, 2> one{x2-d, y2}, two{x1-d, y1};
                if (exists(one) && exists(two)) {
                    ans++;
                }
            }
        } else {
            for (auto [x1, y1] : y[a[i][1]]) {
                auto [x2, y2] = a[i];
                if (x2 <= x1) break;
                int d = x2-x1;

                ar<int, 2> one{x2, y2-d}, two{x2-d, y2-d};
                if (exists(one) && exists(two)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}