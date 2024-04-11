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
const int MAXN = 3e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll x; cin >> x;
    vector<ll> pf; ll nx=x;
    for (ll i = 2; i*i <= nx; i++) if (nx%i == 0) {
        pf.push_back(1);
        while (nx%i == 0) pf.back() *= i, nx /= i;
    }
    if (nx > 1) pf.push_back(nx);
    auto get = [&](ll v) -> pair<ll, pair<ll, ll>> {
        ll need=1;
        for (auto it : pf) if (v%it != 0) need *= it;
        return {max(v, need), {v, need}};
    };
    pair<ll, pair<ll, ll>> ans={x, {1, x}};
    for (ll i = 2; i*i <= x; i++) if (x%i == 0) {
        ans = min(ans, get(i));
        ans = min(ans, get(x/i));
    }
    cout << ans.second.first << ' ' << ans.second.second << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}