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
typedef long long ll;
void fsc(ll &x){
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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, k;
string s;
vector<int> in[MAXN];

struct DSU {
    int p[MAXN], sz[MAXN], ans[MAXN], flipped[MAXN], state[MAXN], canFlip[MAXN], tot=0;
    vector<int> items[MAXN];
    void init(){ 
        for (int i = 0; i < k; i++) {
            items[i].push_back(i), p[i] = i;
            sz[i] = canFlip[i] = 1; ans[i] = flipped[i] = state[i] = 0;
        }
    }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    int get_st(int v){ return state[v]^flipped[find_set(v)]; }
    void flip_set(int v){
        v = find_set(v);
        flipped[v] ^= 1; tot -= ans[v];
        ans[v] = sz[v]-ans[v]; tot += ans[v];
    }
    void set(int v, int st){
        if (get_st(v) == st){
             canFlip[find_set(v)]=0; return;
        }
        assert(canFlip[find_set(v)]);
        flip_set(v); canFlip[find_set(v)]=0;
    }
    void union_sets(int a, int b, int st){
        // cerr << "U: " << a << ' ' << b << ' ' << st << '\n';
        int oa = a, ob = b;
        a = find_set(a), b = find_set(b);
        assert(sz[a] == sz(items[a]) && sz[b] == sz(items[b]));
        if (a == b) { assert(get_st(oa) == (get_st(ob)^st)); return; }
        if (sz[a] < sz[b]) swap(a, b);
        if (get_st(oa) != (get_st(ob)^st)){ //either flip a or b
            int costa = sz[a]-2*ans[a], costb = sz[b]-2*ans[b];
            assert(canFlip[a] || canFlip[b]);
            // cerr << "COST: " << sz[a] << ' ' << ans[a] << ' ' << costa << ' ' << costb << '\n';
            if (canFlip[a] && canFlip[b]){
                if (costa < costb){ //flip a
                    flip_set(a); //cerr << "FLIP: " << a << '\n';
                } else { //flip b
                    flip_set(b); //cerr << "FLIP: " << b << '\n';
                }
            } else if (canFlip[a]){
                flip_set(a);
            } else if (canFlip[b]) {
                flip_set(b);
            }
        }
        for (auto it : items[b]){
            items[a].push_back(it);
            if (flipped[a] != flipped[b]){
                state[it] ^= 1;
            }
        }
        flipped[b] = 0;
        items[b].clear();
        canFlip[a] &= canFlip[b];
        p[b] = a, sz[a] += sz[b], sz[b] = 0; ans[a] += ans[b], ans[b] = 0;
        // cerr << "ANS: " << ans[a] << '\n';
    }
} d;

void solve(){
    cin >> n >> k >> s;
    for (int i = 0; i < k; i++){
        int c; cin >> c;
        while (c--){
            int a; cin >> a, --a; in[a].push_back(i);
        }
    }
    d.init();
    for (int i = 0; i < n; i++){ //adding the ith thing
        assert(sz(in[i]) <= 2);
        if (sz(in[i]) == 1) d.set(in[i][0], 1^(s[i]-'0'));
        else if (sz(in[i]) == 2) d.union_sets(in[i][0], in[i][1], 1^(s[i]-'0'));
        // cerr << (1^(s[i]-'0')) << '\n';
        // for (int j = 0; j < k; j++) cerr << d.get_st(j) << ' ';
        // cerr << '\n';
        cout << d.tot << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}