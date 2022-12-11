#include <iostream>

using namespace std;

const long long mod = 1e9 + 7ll;
const int N = 2e5 + 10;

long long fac[N];
long long a[N];
int n;

long long pw(long long a, long long b) {
    if (b == 0ll) return 1ll;
    long long r = pw(a, b / 2);
    r = (r * r) % mod;
    if (b % 2) r = (a * r) % mod;
    return r;
}
long long inv(long long x) { return pw(x, mod-2ll); }
long long C(int x, int r) {
    long long ans = fac[x];
    ans = (ans * inv(fac[r])) % mod;
    ans = (ans * inv(fac[x-r])) % mod;
    return ans;
}
int main(void) {

    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    fac[0] = 1ll;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (fac[i-1] * i) % mod;
    }

    if (n == 1) { cout << a[0] << endl; return 0; }

    if (n % 2 == 1) {
        for (int i = 0; i < n-1; ++i) {
            a[i] = a[i] + (i % 2 ? -a[i+1] : a[i+1]);
        }
        --n;
    }

    int x = n / 2;
    long long ans = 0ll;
    for (int i = 0; i < n; ++i) {
        a[i] = (i % 2 and n % 4 == 0 ? -a[i] : a[i]) % mod;
        ans = (ans + a[i] * C(x-1, i / 2)) % mod;
    }

    ans = (ans % mod + mod) % mod;

    cout << ans << endl;

    return 0;
}