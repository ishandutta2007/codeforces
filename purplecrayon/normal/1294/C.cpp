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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll x; cin >> x;
    vector<ll> pf; ll ox=x;
    for (ll i = 2; i*i <= x; i++){
        while (x%i == 0) pf.push_back(i), x /= i;
    }
    if (x != 1) pf.push_back(x);
    auto chk = [&](ll a, ll b, ll c) -> bool {
        return a != b && a != c && b != c;
    };
    if (sz(pf) < 3) { cout << no; return; }
    if (sz(pf) < 6){ //bf
        //ch
        ll l=1;
        for (int i = 0; i < sz(pf); i++){
            l *= pf[i]; ll r=1;
            for (int nxt = i+1; nxt < sz(pf); nxt++){
                r *= pf[nxt]; ll f = ox/l/r;
                if (l != 1 && r != 1 && f != 1 && chk(l, r, f)){ cout << yes << l << ' ' << r << ' ' << f << '\n'; return; }
            }
        }
        cout << no;
    } else {
        cout << yes << pf[0] << ' ' << (pf[1]*pf[2]) << ' ';
        ll y=1; for (int i = 3; i < sz(pf); i++) y *= pf[i];
        cout << y << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}