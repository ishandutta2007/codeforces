#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 1e6 + 2, L = 20;

int binpow(int a, int b) {
    if (!b) return 1ll;
    if (b & 1) return a * binpow(a, b - 1) % mod;
    int t = binpow(a, b / 2);
    return t * t % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n, m; cin >> n >> m;
    int ans = n % mod * (m % mod) % mod, cur = 0;
    m = min(n, m);
    for (int left = 1, right; left <= n; left = right + 1) {
        right = n / (n / left);
        int val = n / left;
        int L = left, R = min(m, right);
        if (R < L) continue;
        int add = (L + R) % mod * ((R - L + 1) % mod) % mod;
        cur += (add * binpow(2, mod - 2)) % mod * (val % mod) % mod;
        cur %= mod;
    }
    cout << ((ans - cur) % mod + mod) % mod << '\n';
    return 0;
}