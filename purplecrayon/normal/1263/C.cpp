#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXM = 3e3+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll LINF = 1e18+10;

void solve(){
    ll n; cin >> n;
    vector<ll> ans;
    ans.push_back(0); ans.push_back(1);
    auto nxt = [&](ll x){
        // how to determine if a number can be used
        // n/(n/v) -> v
        x++;
        return n/(n/x);
    };
    while (ans.back() < n){
        auto v = nxt(ans.back());
        ans.push_back(v);
    }
    // for (ll i=2; i <= n; i++)
        // if (n/(n/i) == i) ans.push_back(i), cout  << "GOOD: " << i << ' ' << (n/(n/i)) << "\n";
        // else cout << "BAD: " << i << ' ' << (n/(n/i)) << "\n";
    cout << sz(ans) << "\n";
    for (auto it : ans) cout << it << ' ';
    cout << "\n";
    // cout << "\n\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}