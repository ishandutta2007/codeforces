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
const int MAXN = 2e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 21, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

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


const int MAXV = 1e7+10;
int pf[MAXV];

void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}
int get_pf(int n){
    hash_map<int, int> mp;
    int c=n;
    while (c > 1){
        mp[pf[c]]++;
        c /= pf[c];
    }
    int r=1;
    for (auto& p : mp) if (p.second&1)
        r *= p.first;
    return r;
}

int dp[MAXN][MAXK], cidx[MAXK];

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& it : a) cin >> it, it = get_pf(it);

    vector<int> nxt(n, -1);
    hash_map<int, int> mp;
    for (int i = n-1; i >= 0; i--){
        if (mp.find(a[i]) != mp.end()){
            nxt[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }

    vector<vector<int>> rb(n);
    for (int i = 0; i < n; i++) if (nxt[i] != -1){
        rb[nxt[i]].push_back(i);
    }
    set<int> s;

    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) dp[i][j]=1e9+10;

    for (int i = 0; i < n; i++){
        for (auto& it : rb[i]) s.insert(it);
        int cn = min(k+1, sz(s));
        if (cn) { //find prev locations
            auto it = prev(s.end()); 
            for (int j = 0; j < cn; j++){
                cidx[j] = *it;
                if (j < cn-1) it = prev(it);
            }
        } 

        for (int j = 0; j <= k; j++){
            if (j >= cn) dp[i][j] = 1;
            else {
                for (int l = 0; l <= j; l++){
                    int cdp = dp[cidx[l]][j-l];
                    dp[i][j] = min(dp[i][j], 1+cdp);
                }
            }
        }
    }
    cout << dp[n-1][k] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1; pre();
    cin >> t_c;
    while (t_c--) solve();
}