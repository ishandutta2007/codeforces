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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;


void solve(){
    ll x, n; cin >> x >> n;
    vector<ll> pf;
    for (ll i = 2; i*i <= x; i++) if (x%i == 0) {
        pf.push_back(i);
        while (x%i == 0) x /= i;
    }
    if (x > 1) pf.push_back(x);
    ll ans=1;
    auto po = [&](ll b, ll p){
        ll r=1;
        for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
        return r;
    };
    for (auto it : pf){
        __int128 cur=it, amt=0;
        while (cur <= n){
            amt = (amt+n/cur);
            cur = cur*it;
        }
        ans = ans*po(it, amt)%MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}