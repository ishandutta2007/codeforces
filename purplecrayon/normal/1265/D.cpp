#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

/*struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n) { iota(p, p+n, 0); fill(sz, sz+n, 1); }
    void make_set(int v){ p[v]=v, sz[v]=1; }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b]=a, sz[a]+=sz[b], sz[b]=0;
    }
} d;*/

void solve(){
    //any zero must be paired with a one
    //any three must be paired with a two
    //either do 01010101232323232
    //or 10101012323232
    int cnt[4]; cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    auto get = [&](int st, int en) -> vector<int> {
        int n=cnt[0]+cnt[1]+cnt[2]+cnt[3];
        vector<int> ans(n); for (auto& it : ans) it = rand()%(int(1e8));
        int ost=(st==0?1:0), oen=(en==2?3:2);
        auto set = [&](int i, int v) -> bool {
            if (i >= 0 && i < n){ ans[i]=v; return true; }
            return false;
        };
        for (int i = 0; i/2 < cnt[st]; i+=2) if (!set(i, st)) return {};
        for (int i = 1; i/2 < cnt[ost]; i+=2) if (!set(i, ost)) return {}; 
        for (int i = 0; i/2 < cnt[en]; i+=2) if (!set(n-1-i, en)) return {}; 
        for (int i = 1; i/2 < cnt[oen]; i+=2) if (!set(n-1-i, oen)) return {}; 
        for (int i = 1; i < n; i++) if (abs(ans[i]-ans[i-1])!=1) return {};
        return ans;
    };
    for (auto st : {0, 1}) for (auto en : {2, 3}){
        vector<int> v = get(st, en);
        if (sz(v)){
            cout << yes;
            for (auto it : v) cout << it << ' ';
            cout << "\n"; return;
        }
    }
    cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}