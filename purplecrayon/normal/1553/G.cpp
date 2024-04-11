#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1.5e5+10, MOD = 1e9+7;

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
} d;

#include <bits/extc++.h>
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

const int MAXV = 1e6+10;
int pf[MAXV];


void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}
vector<pair<int, int>> get_pf(int n){
    vector<pair<int, int>> r;
    int c=n;
    while (c > 1){
        int v = pf[c];
        r.emplace_back(v, 0);
		while (c%v == 0) r.back().second++, c /= v;
    }
    return r;
}

int n, q;
int a[MAXN];
hash_set<ll> has;

void solve(){
    cin >> n >> q;

    d.init(MAXV), pre();
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        int prv = -1;
        for (auto [p, cnt] : get_pf(a[i])) {
            if (prv != -1) d.union_sets(p, prv);
            prv = p;
        }
    }
    for (int i = 0; i < n; i++) {
        auto v1 = get_pf(a[i]);
        auto v2 = get_pf(a[i]+1);
        
        vector<int> root;

        for (auto [p, cnt] : v1) root.push_back(d.find_set(p));
        for (auto [p, cnt] : v2) root.push_back(d.find_set(p)); 

        for (int r1 : root) for (int r2 : root) {
            has.insert(ll(r1)*MAXV+r2), has.insert(ll(r2)*MAXV+r1);
        }
    }


    while (q--) {
        int x, y; cin >> x >> y, --x, --y;

        unordered_set<int> root;
        for (auto [p, cnt] : get_pf(a[x])) {
            root.insert(d.find_set(p));
        }
        int ans = -1;
        for (auto [p, cnt] : get_pf(a[y])) {
            if (root.count(d.find_set(p))) {
                ans = 0;
            }
        }

        if (ans == -1) {
            for (auto [p1, cnt] : get_pf(a[x])) for (auto [p2, cnt] : get_pf(a[y])) {
                int r1 = d.find_set(p1), r2 = d.find_set(p2);
                if (has.find(ll(r1)*MAXV+r2) != has.end()) ans = 1;
            }
        }
        if (ans == -1) ans = 2;

        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}