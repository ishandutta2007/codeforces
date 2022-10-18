#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    function<int(int, int, ll)> binpow = [&](int a, int b, ll MOD) -> int {
        if (b == 0) {
            return 1;
        }
        if (b & 1) {
            return 1LL * binpow(a, b - 1, MOD) * a % MOD;
        }
        return binpow(1LL * a * a % MOD, b >> 1, MOD);
    };
    const ll REALMOD = 1e9 + 7;
    cout << 1LL * binpow(16, binpow(2, k - 1, REALMOD - 1) - 1, REALMOD) * 6 % REALMOD;
}