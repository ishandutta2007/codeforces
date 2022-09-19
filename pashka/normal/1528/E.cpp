#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int mod = 998244353;

long mult(long a, long b) { return (a * b) % mod; }

long power(long a, long b) {
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

long inv(long a) {
    return power(a, mod - 2);
}

struct mint {
    int value;

    constexpr mint() : value() {}

    mint(const long &x) {
        value = normalize(x);
    }

    static long normalize(const long &x) {
        long v = x % mod;
        if (v < 0) v += mod;
        return v;
    }

    bool operator==(const mint &x) { return value == x.value; };

    mint operator+(const mint &x) { return value + x.value; };
    mint operator-(const mint &x) { return value - x.value; };

    mint operator*(const mint &x) { return (long) value * x.value; };

    void operator+=(const mint &x) { value = normalize(value + x.value); };
};


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<mint> d(n + 1);
    vector<mint> ps(n + 1);
    ps[0] = d[0] = 1;
    mint inv2 = inv(2);
    mint inv3 = inv(3);
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + (d[i - 1] * d[i - 1] + d[i - 1]) * inv2;
        if (i > 1) {
            d[i] += d[i - 1] * ps[i - 2];
        }
        ps[i] = ps[i - 1] + d[i];
//        cout << i << " " << d[i].value << "\n";
    }
    mint res = d[n];
    if (n > 1) {
        res += d[n - 1] * (ps[n - 2] * ps[n - 2] + ps[n - 2]);
        res += (d[n - 1] * d[n - 1] + d[n - 1]) * ps[n - 2];
    }
    res += (d[n - 1] * d[n - 1] * d[n - 1] +
            d[n - 1] * d[n - 1] * 3 +
            d[n - 1] * 2) * inv3;

    for (int a = 1; a <= n; a++) {
        mint s = a == n ? 1 : d[n - a - 1];
        if (a > 1) {
            res += s * d[a - 1] * ps[a - 2];
        }
        res += s * (d[a - 1] * d[a - 1] + d[a - 1]) * inv2;
    }



    cout << res.value << "\n";


    return 0;
}