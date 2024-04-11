#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    ll p = 2;
    
    cin >> n;
    
    for (ll k = 1; k <= n; k++) {
        ll t = (k + 1) * (k + 1) * k - p;
        #ifdef LOCAL
            ll x = k * t + k * p;
            cout << x << " " << x % (k + 1) << endl;
        #endif
        p = k;
        cout << t << "\n";
    }
    
    return 0;
}