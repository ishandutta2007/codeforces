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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 25, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    ll ans=0;
    for (int x = 0; x < MAXB; x++){
        //take everything mod (1<<x)
        vector<ll> v; v.reserve(n); for (auto& it : a) v.push_back(it%(1<<(x+1)));
        sort(v.begin(), v.end()); ll nm=0;
        auto get = [&](ll l, ll r, int i) -> int { //num elements in [l, r)
            l -= v[i], r -= v[i];
            int lq = lower_bound(v.begin(), v.end(), l)-v.begin();
            int rq = lower_bound(v.begin(), v.end(), r)-v.begin()-1;
            lq = max(lq, i+1);
            return max(rq-lq+1, 0);
        };
        for (int i = 0; i < n; i++){
            nm += get(1<<x, 1<<(x+1), i);
            nm += get((1<<x)|(1<<(x+1)), 1<<(x+2), i);
        }
        //to check whether the xth bit is on, the number has to be >= (1<<x) && < (1<<(x+1))
        if (nm&1) ans ^= (1ll<<x);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}