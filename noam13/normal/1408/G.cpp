#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(),x.end()
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;
const int INF = 4e18, MOD = 998244353;
template <int maxn> struct NTT {
    #ifdef int
        #define needint64
        #undef int
    #endif
    constexpr static int lg2(int n) { return 32 - __builtin_clz(n - 1); }
    const static int MAXN = 1 << lg2(maxn), MOD = 998244353, root = 3;
    int rev[MAXN], rt[MAXN];

    int mul(int a, int b) { return (long long)a * b % MOD; }
    int sub(int a, int b) { return b > a ? a - b + MOD : a - b; }
    int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }

    int binExp(int base, long long exp) {
        if (exp == 0)
            return 1;
        return mul(binExp(mul(base, base), exp / 2), exp & 1 ? base : 1);
    }
    NTT() {
        rt[1] = 1;
        for (int k = 1; k < lg2(MAXN); k++) {
            int z[] = {1, binExp(root, (MOD - 1) >> (k + 1))};
            for (int i = (1 << k); i < 2 << k; i++)
                rt[i] = mul(rt[i / 2], z[i & 1]);
        }
    }
    void ntt(int *a, int n) {
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i / 2] | (i & 1) << lg2(n)) / 2;
        for (int i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k)
                for (int j = 0; j < k; j++) {
                    int z = mul(rt[j + k], a[i + j + k]);
                    a[i + j + k] = sub(a[i + j], z);
                    a[i + j] = add(a[i + j], z);
                }
    }
    int in[2][MAXN];
    vector<int> multiply(const vector<int> &a, const vector<int> &b) {
        if (a.empty() || b.empty()) return {};
        int sz = a.size() + b.size() - 1, n = 1 << lg2(sz);
        fill(in[0], in[0]+n, 0), fill(in[1], in[1]+n, 0);
        copy(all(a), in[0]), copy(all(b), in[1]);
        ntt(in[0], n), ntt(in[1], n);
        int invN = binExp(n, MOD - 2);
        for (int i = 0; i < n; i++)
            in[0][i] = mul(mul(in[0][i], in[1][i]), invN);
        reverse(in[0] + 1, in[0] + n);
        ntt(in[0], n);
        return vector<int>(in[0], in[0] + sz);
    }
    #ifdef needint64
        #define int int64_t
        #undef needint64
    #endif
};

struct DSU{
    int n;
    vi p, sz, cnt;
    vb good;
    vvi g;
    DSU(int n): n(n), p(n,-1), sz(n,1), cnt(n,0), good(n,1), g(n){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    void check(int a){
        good.resize(p.size());
        good[a] = (cnt[a] == (sz[a] * (sz[a]-1))/2);
    }
    void uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b){
            cnt[a]++;
            check(a);
            return ;
        }
        p[a] = p[b] = p.size();
        p.pb(-1); 
        sz.pb(sz[a]+sz[b]); 
        cnt.pb(cnt[a]+cnt[b]+1);
        g.resize(p.size()); g.back() = {a,b};
        check(p.size()-1);
    }
};
void add(int32_t &a, int b){
    a = (a+b)%MOD;
}
int n, k;
vvi g;
vector<vector<int32_t>> ans;
vi sz;
vb good;
NTT<2*1505> ntt;
void dfs(int cur){
    for(auto nei:g[cur]){
        dfs(nei);
    }
    if (g[cur].size()){
        int a = g[cur][0], b = g[cur][1];
        /*ans[cur] = ntt.multiply(ans[a], ans[b]);*/
        int nn = ans[a].size(), mm = ans[b].size();
        loop(i,1,nn){
            loop(j,1,mm){
                if (i+j>k) break;
                add(ans[cur][i+j], int(ans[a][i])*ans[b][j]%MOD);
            }
        }
    }
    if (good[cur]) add(ans[cur][1], 1);
    ans[cur].resize(sz[cur]+1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vvi mat(n, vi(n));
    vector<pair<int, ii>> edges;
    loop(i,0,n){
        loop(j,0,n){
            cin>>mat[i][j];
            if (j<i) edges.pb({mat[i][j], {j,i}});
        }
    }
    sort(all(edges));
    DSU dsu(n);
    for(auto e:edges){
        dsu.uni(e.y.x, e.y.y);
    }
    g = dsu.g, good = dsu.good, sz = dsu.sz;
    good.resize(g.size());
    int root = dsu.find(0);
    k =n, n = g.size();
    ans.resize(n, vector<int32_t>(k+1));
    dfs(root);
    loop(i,1,k+1) cout<<ans[root][i]<<" ";
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a

*/