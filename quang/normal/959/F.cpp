#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 20;
const int MOD = 1000000007;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}
 
inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
 
inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, q;
int a[N], p[N];
int basis[LOG];
int numBasis;
int res[N];
vector<pair<int, int>> events[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], 2);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int l, x;
        cin >> l >> x;
        events[l].push_back({x, i});
    }
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        for (int j = LOG - 1; j >= 0; j--) {
            if ((cur >> j & 1) == 0) continue;
            if (!basis[j]) {
                basis[j] = cur;
                numBasis++;
                break;
            }
            cur ^= basis[j];
        }

        for (auto u : events[i]) {
            int val = u.first;
            int found = 0;
            for (int j = LOG - 1; j >= 0; j--) {
                if ((val >> j & 1) == 0) continue;
                if (!basis[j]) {
                    found = 1;
                    break;
                }
                val ^= basis[j];
            }
            if (found) {
                res[u.second] = 0;
            } else {
                res[u.second] = p[i - numBasis];
            }
        }
    }
    for (int i = 1; i <= q; i++) cout << res[i] << '\n';
    return 0;
}