#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
    return a > 0 ? gcd(b % a, a) : b;
}

int main() {
    ll mass, k;
    cin >> mass >> k;
    vector<ll> arr(k);
    for (auto &i : arr) cin >> i;
    ll m = 0, t = 0, ans = 0;
    for (ll i = 0; i < k; ++i) {
        if ((mass / arr[i]) * arr[i] > m) {
            ans = mass / arr[i];
            t = i;
            m = (mass / arr[i]) * arr[i];
        }
    }
    cout << t + 1 << ' ' << ans;
    return 0;
}