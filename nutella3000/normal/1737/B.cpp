#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

ll f(ll r) {
    if (r == 0) return 0;
    
    ll q = sqrtl(r);
    while (q * q > r) --q;
    while ((q+1)*(q+1) <= r) ++q;

    return 3*q + ((q+1) * q <= r) + ((q+2) * q <= r) - 2;
}

void run() {
    ll l, r; cin >> l >> r;
    cout << f(r) - f(l-1) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}