#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, p = 239, N = 4e5 + 5;

struct mint {
    int x;
    mint(int x = 0) : x (x % mod) {}
    mint operator+(mint a) const {
        int res = x + a.x;
        if (res >= mod) return res - mod;
        return res;
    }
    mint operator-(mint a) const {
        int res = x - a.x;
        if (res < 0) return res + mod;
        return res;
    }
    mint operator*(mint a) const {
        return x * a.x % mod;
    }
    bool operator==(mint a) const {
        return x == a.x;
    }
    mint bpow(int b) {
        if (b == 0) return 1;
        if (b & 1) return (*this).bpow(b - 1) * x;
        mint t = (*this).bpow(b / 2);
        return t * t;
    }
    mint operator/(mint a) const {
        return (*this) * a.bpow(mod - 2);
    }
    friend istream& operator>>(istream& in, mint& a) {
        return in >> a.x;
    }
    friend ostream& operator<<(ostream& out, const mint& a) {
        return out << a.x;
    }
};

vector <mint> fct(N), rfct(N);

mint getC(int n, int k) {
    if (k > n) return 0;
    return fct[n] * rfct[n - k] * rfct[k];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    fct[0] = rfct[0] = 1;

    for (int i = 1; i < N; ++i) {
        fct[i] = fct[i - 1] * i;
        rfct[i] = mint(1) / fct[i];
    }

    int n, k; cin >> n >> k;
    vector <int> s(n), id(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        id[s[i]] = i;
    }
    id[n] = -1;

    vector <int> need(n);

    for (int i = 0; i < n - 1; ++i) {
        int i1 = id[s[i] + 1];
        int i2 = id[s[i + 1] + 1];
        if (i1 > i2) k--;
    }

    if (k < 1) {
        cout << "0\n";
        return 0;
    }

    cout << getC(n + k - 1, k - 1) << '\n';

    return 0;
}