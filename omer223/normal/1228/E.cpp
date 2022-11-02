#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const ll mod = 1e9 + 7;
void imult(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) + (rhs % mod)) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) + (rhs % mod)) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}

const int sz = 3e2;
ll f[sz], finv[sz];
int n, k;

void initchs() {
    f[0] = 1;
    foru(i, 1, sz)f[i] = mult(f[i - 1], i);
    finv[sz - 1] = bpw(f[sz - 1], mod - 2);
    ford(i, sz - 2, 0)finv[i] = mult(finv[i + 1], i + 1);
}

ll choose(int n, int k) {
    if (n < k)return 0;
    return mult(f[n], mult(finv[k], finv[n - k]));
}

int main() {
    fast;
    cin >> n >> k;
    initchs();
    ll tot = 0;
    for (int bads = 1; bads <= 2 * n; bads++) {
        for (int rows = max(0, bads - n); rows <= min(n, bads); rows++) {
            int cols = bads - rows, badArea = (rows + cols) * n - rows * cols;
            ll toadd = mult(bpw(k - 1, badArea), bpw(k, n * n - badArea));
            if (bads & 1)iadd(tot, mult(toadd, mult(choose(n, rows), choose(n, cols))));
            else isubt(tot, mult(toadd, mult(choose(n, rows), choose(n, cols))));
        }
    }
    cout << subt(bpw(k, n * n), tot);
    return 0;
}