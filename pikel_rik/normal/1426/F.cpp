#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

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

int n;
string s;
ll pw[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = 3 * pw[i - 1] % mod;

    cin >> n >> s;
    int k = 0;
    for (char ch : s) {
        k += ch == '?';
    }

    int cnta = 0, cntx = 0, active = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            cnta++;
        } else if (s[i] == 'b') {
            active = (active + cnta * pw[k]) % mod;
            if (cntx > 0) {
                active = (active + cntx * pw[k - 1]) % mod;
            }
        } else if (s[i] == 'c') {
            ans = (ans + active) % mod;
        } else {
            ans = (ans + active * modinv(3)) % mod;
            active = (active + cnta * pw[k - 1]) % mod; //3^k - 1
            if (cntx > 0) {
                active = (active + cntx * pw[k - 2]) % mod;
            }
            cntx++;
        }
    }
    cout << ans << '\n';
    return 0;
}