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
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
struct my_hash {
    const uint64_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x + RANDOM);
    }
};
gp_hash_table<int,int,my_hash> mp, mp1, mp2, all;
//unordered_map<int, int> mp, all;

int n, a[MAXN], cnt1[MAXN], cnt2[MAXN];
vector<int> adj[MAXN];

int dfs1(int c=0, int p=-1){
    int ans=(mp[a[c]]?1:0);
    mp[a[c]]++;
    for (auto nxt : adj[c]) if (nxt != p) ans += dfs1(nxt, c);
    mp[a[c]]--;
    return ans;
}
void dfs_cnt(int c=0, int p=-1){
    int o1=0, o2=0, ov=0;
    if (c){
        o1 = mp1[a[p]];
        o2 = mp2[a[c]];
        ov = mp1[a[c]];
    }
    mp1[a[c]]++, mp2[a[c]]++;
    for (auto nxt : adj[c]) if (nxt != p) dfs_cnt(nxt, c);
    mp1[a[c]] = ov+1;
    if (c) cnt1[c] = mp1[a[p]]-o1, cnt2[c] = all[a[c]]-(mp2[a[c]]-o2);
}
int dfs2(int c, int p, int pv){
    pv -= cnt1[c], pv += cnt2[c];
    int ans=(pv==0);
    for (auto nxt : adj[c]) if (nxt != p) ans += dfs2(nxt, c, pv);
    return ans;
}
void solve(){
    //if my parent is bad, i can only be good if the only matches are from him into my subtree
    //if my parent is good, i can only be bad if i match from myself into his subtree
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], all[a[i]]++;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    dfs_cnt();

    int v=dfs1();
    int ans=(v==0);
    for (auto nxt : adj[0]){
        ans += dfs2(nxt, 0, v);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}