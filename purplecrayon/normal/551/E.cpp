#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

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

int n, q;
ll a[MAXN];

const int B = 500, CNT = MAXN/B;

struct Block {
    int l, r;
    ll delta = 0;
    hash_map<ll, int> mx, mn;

    void push_delta() {
        for (int i = l; i <= r; i++) a[i] += delta;
        delta = 0;
    }
    void bld() {
        mx.clear(); mn.clear();
        delta = 0;
        for (int i = l; i <= r; i++) {
            if (mx.find(a[i]) == mx.end() || mx[a[i]] < i) mx[a[i]] = i;
            if (mn.find(a[i]) == mn.end() || mn[a[i]] > i) mn[a[i]] = i;
        }
    }
    void add(ll x){ delta += x; }
    int get_mx(ll x){ x -= delta; return mx.find(x) == mx.end() ? -1 : mx[x]; }
    int get_mn(ll x){ x -= delta; return mn.find(x) == mn.end() ? n : mn[x]; }
} blocks[CNT];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i*B < n; i++) {
        int l = i*B, r = min(n, (i+1)*B)-1;
        blocks[i].l = l, blocks[i].r = r;
        blocks[i].bld();
    }
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int l, r; ll x; cin >> l >> r >> x, --l, --r;
            int bl = l/B, br = r/B;
            if (bl == br) {
                int b = bl | br;
                blocks[b].push_delta();
                for (int i = l; i <= r; i++) a[i] += x;
                blocks[b].bld();
            } else {
                blocks[bl].push_delta();
                for (int i = l; i <= blocks[bl].r; i++) a[i] += x;
                blocks[bl].bld();

                blocks[br].push_delta();
                for (int i = r; i >= blocks[br].l; i--) a[i] += x;
                blocks[br].bld();

                for (int b = bl+1; b <= br-1; b++) blocks[b].add(x);
            }
        } else {
            ll x; cin >> x;

            int mn = n, mx = -1;
            for (int i = 0; i*B < n; i++) {
                mn = min(mn, blocks[i].get_mn(x));
                mx = max(mx, blocks[i].get_mx(x));
            }
            if (mn > mx) cout << -1 << '\n';
            else cout << mx-mn << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}