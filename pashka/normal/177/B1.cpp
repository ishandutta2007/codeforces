#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    
    ll n0 = n;
    
    vector<ll> p;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            p.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        p.push_back(n);
    }
    
    n = n0;

    long c = n;
    long ans = c;
    for (ll x : p) {
        c /= x;
        ans += c;
    }
    cout << ans << "\n";
}