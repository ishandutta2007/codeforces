#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(a + FIXED_RANDOM);
    }
    template<class T> size_t operator()(T a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        return splitmix64(x(a) + FIXED_RANDOM);
    }
    template<class T, class H> size_t operator()(pair<T, H> a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        hash<H> y;
        return splitmix64(x(a.f) * 37 + y(a.s) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
int bm(int b, int p) {
    if(p == 0) return 1;
    int r = bm(b, p/2);
    if(p&1) return (((r*r) % MOD) * b) % MOD;
    return (r*r) % MOD;
}
int inv(int b) {
    return bm(b, MOD - 2);
}
int w[51][51];
int deg[51];
int n;
vector<pair<int, int> > v;
int weight() {
    int ans = 0;
    for(int i=0; i<v.size(); i++) {
        ans += w[v[i].first][v[i].second];
    }
    return ans;
}
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    int u = uniform_int_distribution<int>(l, r)(rng);
    return u;
}
int dsu[51];
int d[51];
int set_of(int u) {
    if(dsu[u] == u) return u;
    return dsu[u] = set_of(dsu[u]);
}
void union_(int u, int v) {
    dsu[set_of(u)] = set_of(v);
}
bool replace(int c) {
    for(int i=1; i<=n; i++) dsu[i] = i;
    for(int i=0; i<n-1; i++) {
        if(i != c) union_(v[i].first, v[i].second);
    }
    deg[v[c].first]--;
    deg[v[c].second]--;
    vector<int> l1, l2;
    for(int i=1; i<=n; i++) {
        if(set_of(i) == set_of(1)) l1.push_back(i);
        else l2.push_back(i);
    }
    int L1 = l1.size();
    int L2 = l2.size();
    int node1, node2;
    int tries = 100; bool found = 0;
    while(tries--) {
        int node1 = l1[rnd(0, L1-1)];
        int node2 = l2[rnd(0, L2-1)];
        if(deg[node1] + 1 <= d[node1] && deg[node2] + 1 <= d[node2]) {
            v[c] = {node1, node2};
            found = 1;
            deg[node1]++;
            deg[node2]++;
            break;
        }
    }
    return found;
}
void solve(int tc){
    time_t t=clock();
    int k; cin>>n>>k;
    for(int i=1;i<=k; i++) cin >> d[i];
    for(int i=k+1; i<=n; i++) d[i] = 100;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            cin >> w[i][j];
            w[j][i] = w[i][j];
        }
        w[i][i] = 0;
    }
    for(int i=1; i<n; i++) {
        v.push_back({i, n});
    }
    for(int i=1; i<n; i++) deg[i] = 1;
    deg[n] = n-1;
    int ans = weight();
    while(1) {
        v.clear();
        for(int i=1; i<n; i++) {
            v.push_back({i, n});
        }
        for(int i=1; i<n; i++) deg[i] = 1;
        deg[n] = n-1;
        int prev = weight();
        for(double t=10000; t>=1e-8; t*=0.998) {
            int c, x, y;
            while(1) {
                c = rnd(0, n-2);
                x = v[c].first, y = v[c].second;
                if(replace(c)) {
                    break;
                }
            }
            int now = weight();
            if(now >= prev) {
                double P = exp((prev-now)*1.0/t);
                if(P < (double)rand() / RAND_MAX) {
                    deg[v[c].first]--;
                    deg[v[c].second]--;
                    v[c] = {x, y};
                    deg[x]++;
                    deg[y]++;
                }
                else { 
                    prev = now;
                }
            }
            else {
                prev = now;
            } 
            ans = min(ans, now);
        }
        if((double)(clock()-t)*1.0/CLOCKS_PER_SEC > 5.9) {
            break;
        }
    }
    cout << ans << "\n";
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
//    cin >> t;
    int cnt = 0;
    while(t--){
        solve(++cnt);
    }
}