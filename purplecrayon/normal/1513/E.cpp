#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
long long fact[maxn];

long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

long long divide(long long a, long long b) {
    return (a * binpow(b, mod - 2, mod)) % mod;
}

long long nCr(long long a, long long b) {
    long long res = fact[a];
    res = divide(res, fact[b]);
    res = divide(res, fact[a - b]);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << 0 << "\n";
        return 0;
    }
    long long goal = sum / n;
    int source = 0, sink = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > goal) {
            ++source;
        } else if (a[i] < goal) {
            ++sink;
        }
    }
    if (source == 0 && sink == 0) {
        cout << 1 << "\n";
        return 0;
    }
    map<int, int> occ_src, occ_sink;
    for (int i = 0; i < n; ++i) {
        if (a[i] > goal) {
            ++occ_src[a[i]];
        } else if (a[i] < goal) {
            ++occ_sink[a[i]];
        }
    }
    if (source == 1 || sink == 1) {
        long long ans = fact[n];
        for (auto i : occ_sink) {
            ans = divide(ans, fact[i.second]);
        }
        for (auto i : occ_src) {
            ans = divide(ans, fact[i.second]);
        }
        cout << divide(ans, fact[n-source-sink]) << "\n";
        return 0;
    }
    long long si = fact[sink];
    for (auto i : occ_sink) {
        si = divide(si, fact[i.second]);
    }
    long long sr = fact[source];
    for (auto i : occ_src) {
        sr = divide(sr, fact[i.second]);
    }
    long long sol = (2 * si * sr) % mod;
    sol *= nCr(n, source + sink);
    cout << sol % mod << "\n";
    return 0;
}