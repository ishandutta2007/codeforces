#include <bits/stdc++.h>
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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, x, pos; cin >> n >> x >> pos, x--;
    int g=0, l=0;
    int lo=0, hi=n;
    while (lo < hi){
        int mid=(lo+hi)/2;
        if (mid <= pos){
            lo = mid+1;
            if (mid != pos) l++;
        } else {
            hi = mid;
            g++;
        }
    }
    auto po = [&](ll b, ll p){
        ll r=1;
        for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
        return r;
    };
    auto inv = [&](ll x){
        return po(x, MOD-2);
    };
    vector<ll> facts(n+1, 1), ifacts(n+1, 1);
    for (int i = 2; i <= n; i++) facts[i] = i*facts[i-1]%MOD, ifacts[i] = inv(facts[i]);
    auto nck = [&](ll nc, ll kc){
        return facts[nc]*ifacts[nc-kc]%MOD*ifacts[kc]%MOD;
    };
    ll nmG = n-x-1, nmL = x;
    // cout << g << ' ' << l << '\n';
    if (nmG < g || nmL < l){ cout << "0\n"; return; }
    //(nmG choose g)*(g!) * (nmL choose l)*(l!) * (n-l-g)!
    //need to permute 
    cout << nck(nmG, g)*facts[g]%MOD*nck(nmL, l)%MOD*facts[l]%MOD*facts[n-l-g-1]%MOD << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}