#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

bool isPrime(int x) {
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    mod = n;

    if (n == 1) {
        cout << "YES\n1\n";
        return 0;
    }
    if (n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }
    if (!isPrime(n)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << 1 << '\n';
    for (int i = 2; i < n; i++) {
        cout << i * modinv(i - 1) % mod << '\n';
    }
    cout << n << '\n';
    return 0;
}