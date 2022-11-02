#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }


void run() {
    int n, q; cin >> n >> q;
    vector<ll> a(n+1);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i+1];
        b[i] = max(i ? b[i-1] : 0ll, a[i+1]);
        a[i+1] += a[i];
    }
    while (q--) {
        int k; cin >> k;
        auto it = upper_bound(all(b), k) - b.begin();
        cout << a[it] << ' ';
    }
    cout << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}