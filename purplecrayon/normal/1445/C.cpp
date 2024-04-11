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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll p, q; cin >> p >> q;
    if (p%q) { cout << p << '\n'; return; }
    vector<pair<ll, int>> pf; ll cq = q;
    for (ll i = 2; i*i <= cq; i++) if (cq%i == 0){
        pf.push_back({i, 0});
        while (cq%i == 0) pf.back().second++, cq /= i;
    }
    if (cq > 1) pf.push_back({cq, 1});
    ll ans=-1;
    for (auto it : pf){
        ll cp=p;
        while (cp%it.first == 0) cp /= it.first;
        for (int i = 0; i < it.second-1; i++) cp *= it.first;
        ans = max(ans, cp);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}