#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

int power(int a) {
    if (a == 0) return -1;
    return 63 - __builtin_clzll(a);
}

int n;

pii dick(int a, int b) {
    int res = 0;
    for (int bit = 0; bit < n; ++bit) {
        if (a >> bit & 1) {
            res ^= 1ll << bit;
            a ^= b << bit;
        }
    }
    return {res, a};
}

int mod = 0;

int mul(int a, int b) {
    int res = 0;
    for (; b; b >>= 1, a <<= 1) {
        if (power(a) >= power(mod)) a ^= mod;
        if (b & 1) res ^= a;
    }
    return res;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

void run() {
    string s; cin >> s;
    s.erase(s.find_last_of('1') + 1);
    int offset = s.find_first_of('1');
    s.erase(0, offset);

    n = siz(s);
    for (int i = 0; i < siz(s); ++i)
        mod += (s[i] - '0') * (1ll << i);

    if (mod == 0) {
        cout << -1 << '\n';
        return;
    }
    if (mod == 1) {
        cout << offset + 1 << " " << n + offset + 1 << '\n';
        return;
    }

    int phi = 1, val = mod;
    for (int i = 3; i <= (1 << ((n+1)/2)); i += 2) {
        if (dick(val, i).se == 0) {
            phi *= (1LL << power(i)) - 1;
            while (dick((val = dick(val, i).fi), i).se == 0)
                phi *= 1LL << power(i);
        }
    }
    if (val > 1) phi *= (1LL << power(val)) - 1;
    int res = 1e15 + 3;

    for (int x = 1; x * x <= phi; x++) {
        if (phi % x == 0) {
            if (binpow(2, x) == 1) chmin(res, x);
            if (binpow(2, phi / x) == 1) chmin(res, phi/x);
        }
    }
    cout << 1 + offset << " " << 1 + offset + res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}