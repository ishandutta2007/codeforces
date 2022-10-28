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
const int MAXN = 1.5e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll a, b; cin >> a >> b;
    string s; cin >> s; int n = sz(s);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        if (!sz(v) || s[i]-'0' != v.back().first) v.push_back({s[i]-'0', 1});
        else v.back().second++;
    }
    reverse(v.begin(), v.end());
    int c=0; while (!c && sz(v)) c += v.back().first, v.pop_back();
    reverse(v.begin(), v.end());
    if (!c){ cout << "0\n"; return; }
    ll ans=a;
    for (int i = 0; i < sz(v); i++) if (v[i].first) {
        ll c=a;
        if (i){ //can connect to prev
            ll px = v[i-1].second, cc = px*b;
            c = min(cc, c);
        }
        ans += c;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}