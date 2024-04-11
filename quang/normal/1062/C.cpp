#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int n, q;
string s;
int p[N];
int sum[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    cin >> s;
    s = "q" + s;
    sum[0] = 0;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i] == '1');
        p[i] = add(p[i - 1], p[i - 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int x = sum[r] - sum[l - 1];
        int y = (r - l + 1) - x;
        cout << mul(p[y], sub(p[x], 1)) << '\n';
    }
    return 0;
}