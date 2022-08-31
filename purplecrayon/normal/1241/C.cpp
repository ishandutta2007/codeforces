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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    ll n; cin >> n;
    vector<ll> v(n); for (auto& it : v) cin >> it;
    sort(v.begin(), v.end());
    ll x, a, y, b, k; cin >> x >> a >> y >> b >> k;
    ll lc = a*b/__gcd(a, b);
    if (x < y) swap(x, y), swap(a, b);
    auto good = [&](ll m){
        ll on = m;
        ll nlc = min(on/lc, m); m -= nlc;
        ll na = min(on/a-on/lc, m); m -= na;
        ll nb = min(on/b-on/lc, m); m -= nb;
        assert(nlc+na+nb <= n);
        int idx=n-1; ll cur=0;
        for (; idx >= 0 && n-1-idx < nlc; idx--) cur += v[idx]*(x+y)/100;
        for (; idx >= 0 && n-1-idx < nlc+na; idx--) cur += v[idx]*x/100;
        for (; idx >= 0 && n-1-idx < nlc+na+nb; idx--) cur += v[idx]*y/100;
        // cout << cur << '\n';
        return cur >= k;
    };
    int lo=0, hi=n+1, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (good(mid)) hi = mid;
        else lo = mid;
        mid=(lo+hi)/2;
    }
    cout << (hi>n?-1:hi) << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}