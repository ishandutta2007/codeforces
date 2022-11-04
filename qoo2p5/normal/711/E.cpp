#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int MOD = (int) 1e6 + 3;

ll power(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    
    if (y & 1) {
        return x * power(x, y - 1) % MOD;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % MOD;
    }
}

ll n, k;

void run() {
    cin >> n >> k;
    
    {
        ll cur = 1;
        for (int i = 0; i < n; i++) {
            cur *= 2;
            if (cur > LINF) {
                break;
            }
        }
        
        if (cur < k) {
            cout << "1 1\n";
            return;
        }
    }
    
    ll y = 0;
    for (ll q = 2; q < k; q *= 2) {
        y += (k - 1) / q;
    }
    
    ll tmp = power(2, n);
    ll a = power(tmp, k);
    a = a * power(tmp, MOD - 2) % MOD;
    
    ll b = 1;
    if (k <= MOD) {
        for (int i = 1; i < k; i++) {
            ll c = tmp - i;
            if (c < 0) c += MOD;
            b = b * c % MOD;
        }
    } else {
        b = 0;
    }
    
    ll p = (a - b);
    if (p < 0) p += MOD;
    p = p * power(power(2, y), MOD - 2) % MOD;
    ll q = a * power(power(2, y), MOD - 2) % MOD;
    
    cout << p << " " << q << "\n";
}