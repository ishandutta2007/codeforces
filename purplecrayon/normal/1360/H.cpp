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
const int MAXN = 1e5+10, MAXM = 61, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> v(n);
    for (auto& it : v){
        string s; cin >> s;
        for (char c : s) it *= 2ll, it ^= c-'0';
    }
    vector<ll> nv; nv.reserve(n);
    ll k = ((1ll<<m)-n-1)/2+1;
    string res;
    for (ll i = m-1; i > 0; i--){
        ll x=1ll<<i;
        for (auto& it : v) x -= (it>>i)&1^1;
        nv.clear();
        if (k <= x) {
            res += '0';
            for (auto it : v) if ((it>>i)&1^1) nv.push_back(it);
        } else {
            k -= x, res += '1';
            for (auto it : v) if ((it>>i)&1) nv.push_back(it);
        }
        nv.swap(v);
    }
    if (k == 1){
        if (sz(v) && (v[0]&1^1)) res += '1';
        else res += '0';
    } else res += '1';
    cout << res << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}