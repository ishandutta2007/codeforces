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
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n), t(n); iota(t.begin(), t.end(), 0);
    for (auto& it : a) cin >> it;
    int q; cin >> q, q += n;
    vector<pair<int, pair<ll, int>>> v;
    for (int qt = n; qt < q; qt++){
        int ti; cin >> ti;
        if (ti == 1){
            int i; ll v; cin >> i >> v, --i;
            a[i] = v; t[i] = qt;
        } else {
            ll x; cin >> x;
            v.push_back({qt, {x, 0}});
        }
    }
    for (int i = 0; i < n; i++) v.push_back({t[i], {i, 1}});
    sort(v.rbegin(), v.rend()); ll mx=-1e18;
    for (auto& it : v){
        if (it.second.second){
            a[it.second.first] = max(a[it.second.first], mx);
        } else {
            mx = max(mx, it.second.first);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}