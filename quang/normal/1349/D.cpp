#include <bits/stdc++.h>

using namespace std;

template<int MOD>
struct Modular {
    int val;

    Modular(long long u = 0) {
        val = ((u % MOD) + MOD) % MOD;
    }

    bool operator==(const Modular &o) const {
        return val == o.val;
    }

    bool operator!() const {
        return *this == 0;
    }

    Modular operator+(const Modular &o) const {
        int res = val + o.val;
        if (res >= MOD) res -= MOD;
        return {res};
    }

    Modular operator-(const Modular &o) const {
        int res = val - o.val;
        if (res < 0) res += MOD;
        return {res};
    }

    Modular operator*(const Modular &o) const {
        return {1ll * val * o.val % MOD};
    }

    Modular& operator+=(const Modular &o) {
        val += o.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    Modular& operator-=(const Modular &o) {
        val -= o.val;
        if (val < 0) val += MOD;
        return *this;
    }

    Modular& operator*=(const Modular &o) {
        val = 1ll * val * o.val % MOD;
        return *this;
    }

    Modular power(int v) const {
        Modular u = *this;
        Modular res = 1;
        while (v) {
            if (v & 1) res *= u;
            u *= u;
            v >>= 1;
        }
        return res;
    }

    Modular inv() const {
        return {this->power(MOD - 2)};
    }
};
template <int MOD>
ostream& operator<<(ostream& os, const Modular<MOD>& m) {
    return os << m.val;
}
constexpr int MOD = 998244353;
using Mint = Modular<MOD>;

const int N = 300010;

int n;
int a[N];
Mint p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = accumulate(a + 1, a + n + 1, 0);
    Mint invSum = ((Mint)sum).inv();
    for (int i = 0; i < sum; i++) {
        Mint numer = 1;
        if (i) numer += p[i - 1] * i * invSum;
        Mint denom = 1;
        denom -= invSum * i;
        denom -= invSum * (sum - i) * (n - 2) * ((Mint)(n - 1)).inv();
        p[i] = numer * denom.inv();
    }
    for (int i = sum - 1; i >= 0; i--) {
        p[i] += p[i + 1];
    }
    Mint tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += p[a[i]];
    }
    tot -= (p[0] * (n - 1));
    tot *= ((Mint)n).inv();
    cout << tot << endl;
    return 0;
}