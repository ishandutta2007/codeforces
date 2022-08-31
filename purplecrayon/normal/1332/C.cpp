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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld; 
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 24, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n){ iota(p, p+n, 0); fill(sz, sz+n, 1); }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a, sz[a] += sz[b], sz[b] = 0;
    }
} d;
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s; d.init(n);
    for (int i = 0, j = n-1; i < j; i++, j--) d.union_sets(i, j);
    for (int i = 0; i < k; i++) for (int j = i+k; j < n; j+=k) d.union_sets(i, j);
    map<int, vector<int>> ch;
    for (int i = 0; i < n; i++) ch[d.find_set(i)].push_back(i);
    int ans=n;
    for (auto& it : ch){
        int mx[26]={};
        for (auto i : it.second) mx[s[i]-'a']++;
        ans -= *max_element(mx, mx+26);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}