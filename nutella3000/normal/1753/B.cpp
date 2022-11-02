#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }


void run() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a;
    for (int i = 0; i < n; ++i) {
        ll v; cin >> v;
        if (v < x) {
            a.push_back(v);
        }
    }
    a.push_back(x);
    n = a.size();
    sort(all(a));

    ll cnt = 0, last = a[0];

    for (ll i : a) {
        if (i != last) {
            ll w = 1;
            for (int j = last+1; j <= i; ++j) {
                w *= j;
                if (w > cnt) {
                    cout << "No\n";
                    return;
                }
            }
            if (cnt % w != 0) {
                cout << "No\n";
                return;
            }
            cnt /= w;
            last = i;
        }
        ++cnt;
    }
    cout << "Yes\n";
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}