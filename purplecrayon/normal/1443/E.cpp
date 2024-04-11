#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, q, l=MAXL;
ll x=0, ps[MAXN], a[MAXN], f[MAXL];

void bld(){
    int rl = n-l;
    set<int> s; for (int i = rl+1; i <= n; i++) s.insert(i);
    ll cx=x; //cout << "S: "; for (auto it : s) cout << it << ' '; cout << '\n';
    for (int i = rl; i < n; i++){ //blding from left to right
        for (auto it = s.begin(); ; it=next(it)){
            if (cx < f[n-i-1]) { a[i] = *it; s.erase(it); break; }
            cx -= f[n-i-1];
        }
        // cout << "S: "; for (auto it : s) cout << it << ' '; cout << '\n';
    }
    for (int i = rl; i < n; i++){
        ps[i] = a[i]; if (i) ps[i] += ps[i-1];
    }
}
void solve(){
    cin >> n >> q; l = min(l, n);
    f[0]=1; for (int i = 1; i <= l; i++) f[i]=i*f[i-1];
    ps[0] = 1; for (int i = 1; i < n; i++) ps[i] = (i+1)+ps[i-1];
    iota(a, a+n, 1);
    while (q--){
        int ty; cin >> ty;
        if (ty == 1){
            int l, r; cin >> l >> r, l--, r--;
            cout << (ps[r]-(l?ps[l-1]:0)) << '\n';
        } else if (ty == 2) {
            ll c; cin >> c; x += c;
            bld();
            //cout << "BLD:\n" << c << '\n';
            // for (int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
        } else assert(false);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}