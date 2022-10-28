#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    for (int i = n-1; i >= 1; i--){
        a[i] -= a[i-1];
    }
    ll sm=0;
    for (int i = 1; i < n; i++) if (a[i] > 0) sm += a[i];
    /*auto solve = [&]() -> int {
        int binc=0;
        for (int i = 1; i < n; i++) binc += max(0ll, a[i]-a[i-1]);
        int c0 = (a[0]+binc)/2, b0 = a[0]-c0;
        return max(c0, b0+binc);
    };*/
    auto solve = [&]() -> ll {
        ll c0 = (a[0]+sm)/2, b0 = a[0]-c0;
        return max(c0, b0+sm);
    };
    auto add = [&](int i, ll x){
        if (i){
            if (a[i] > 0) sm -= a[i];
            a[i] += x;
            if (a[i] > 0) sm += a[i];
        } else a[i]+=x;
    };
    cout << solve() << '\n';
    int q; cin >> q;
    while (q--){
        int l, r; ll x; cin >> l >> r >> x, --l, --r;
        add(l, x); if (r < n-1) add(r+1, -x);
        //for (int i = l; i <= r; i++) a[i] += x;
        //ll c0 = (a[0]+sm)/2, b0 = a[0]-c0;
        //cerr << sm << '\n';
        //cout << max(c0, b0+sm) << '\n';
        cout << solve() << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}