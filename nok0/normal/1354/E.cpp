#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
const ll INF = 1e18;
template <typename T>
T pow(T a, long long n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

struct UnionFind {
    public:
    vector<int> par;
    UnionFind(int n){
        par=vector<int>(n,-1);
    }
    int root(int x){
        if(par[x]<0)return x;
    return par[x]=root(par[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool merge(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }
    int size(int x){
        return -par[root(x)];
    }
};

VV<> G(5010);

V<> vis(5010, false);
int ans[5010];

ll cnt2;

void dfs(int k, bool p = true){
    if(vis[k]) return;
    if(p == 1) cnt2++;
    p = !p;
    vis[k] = true;
    for(auto v:G[k]){
        dfs(v, p);
    }
}

void dfs2(int k, bool p = true){
    if(vis[k]) return;
    if(p == 1) ans[k] = 2;
    else ans[k] = 1;
    p = !p;
    vis[k] = true;
    for(auto v:G[k]){
        dfs2(v, p);
    }
}

inline void NO(bool b = true) {if(b) {cout << "NO" << '\n'; exit(0);}}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    UnionFind uf(2 * n);
    int x, y, z; cin >> x >> y >> z;
    REP(i, m){
        int a, b; cin >> a >> b; a--; b--;
        uf.merge(a, b + n);
        uf.merge(b, a + n);
        G[a].pb(b);
        G[b].pb(a);
    }
    bool flg = false;
    REP(i, n) if(uf.issame(i, i + n)) flg = true;
    NO(flg);
    V<int> data;
    V<int> X;
    V<bool> Z;
    ll nya = 0;
    REP(i, n){
        if(vis[i]) continue;
        cnt2 = 0;
        dfs(i);
        nya += min(cnt2, uf.size(i) - cnt2);
        Z.pb(cnt2 < uf.size(i) - cnt2);
        data.pb(abs( 2 * cnt2 - uf.size(i)));
        X.pb(i);
    }
    NO(nya > y);
    ll k = y - nya;
	bool dp[SZ(data) + 1][k + 1];
  	REP(i, SZ(data) + 1) REP(j, k+1) dp[i][j] = false;
    dp[0][0] = 1;
    REP(i, SZ(data)){
        REP(j, k + 1) dp[i+1][j] = (dp[i+1][j] or dp[i][j]);
        REP(j, k + 1) if(j + data[i] <= k) dp[i+1][j+data[i]] = (dp[i+1][j+data[i]] or dp[i][j]);
    }
    NO(!dp[SZ(data)][k]);
    cout << "YES" << endl;
    V<> used(SZ(data), false);
    RREP(i, SZ(data)){
        if(k - data[i] >= 0) if(dp[i][k - data[i]] == true){
            used[i] = true;
            k -= data[i];
        }
    }
	REP(i, n) vis[i] = false;
    REP(i, SZ(X)) dfs2(X[i], used[i] xor Z[i]);
    REP(i, n){
        if(ans[i] == 2) cout << 2;
        if(ans[i] == 1){
            if(x){
                cout << 1;
                x--;
            }
            else cout << 3;
        }
    }
}