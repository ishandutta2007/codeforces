#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll modexp(ll x, int n) {
    if (n == 0)
        return 1;
    ll ans = modexp((x * x) % mod, n / 2);
    if (n % 2 != 0)
        return (x * ans) % mod;
    return ans;
}

int modinv(int x) {
    return modexp(x, mod - 2);
}

bool ok(int n, int a, int b) {
    while (n > 0) {
        if (n % 10 != a and n % 10 != b)
            return false;
        n /= 10;
    }
    return true;
}

ll fact[1000001];

ll choose (int n, int k) {
    ll n1 = fact[n];
    ll n2 = fact[n - k] * fact[k];
    n2 %= mod;

    return (n1 * modinv(n2)) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (i * fact[i-1]) % mod;
    }

    ll c = 0;
    for (int i = 0; i <= n; i++) {
        int sum = a * i + b * (n - i);
        if (ok(sum, a, b))
            c = (c + choose(n, i)) % mod;
    }

    cout << c << "\n";
    return 0;
}