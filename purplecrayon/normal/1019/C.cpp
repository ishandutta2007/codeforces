#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

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

int n, m;
vector<int> adj[MAXN];
bool bad[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }
    memset(bad, 0, sizeof(bad));
    vector<int> st;
    for (int i = 0; i < n; i++) if (!bad[i]) {
        st.push_back(i);
        for (auto nxt :  adj[i]) bad[nxt] = 1;
    }

    memset(bad, 0, sizeof(bad));
    reverse(st.begin(), st.end());
    
    vector<int> ans;
    for (auto i : st) if (!bad[i]) {
        ans.push_back(i);
        for (auto nxt : adj[i]) bad[nxt] = 1;
    }
    cout << sz(ans) << '\n';
    for (auto i : ans) cout << i+1 << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    // cin >> t_c;
    while (t_c--) solve();
}