#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;

void sort(vector<ll> &arr) {
    sort(arr.begin(), arr.end());
}

istream& operator>>(istream &is, vector<ll> &a) {
    for (auto &i : a) cin >> i;
    return is;
}

ll gcd(ll a, ll b) {
    return a > 0 ? (b % a, a) : b;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void solve() {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    if (x * q == p * y) {
        cout << 0 << '\n';
        return;
    }
    if (p == 0 && x != 0 || p == q && x != y || p == 0 && x != 0) {
        cout << -1 << '\n';
        return;
    }
    ll l = (x + p - 1) / p - 1, r = 1e10;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if ((y + (m * p - x) + q - 1) / q <= m) r = m;
        else l = m;
    }
    cout << r * q - y;
    cout << '\n';
}  

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) 
        solve();
    return 0;
}