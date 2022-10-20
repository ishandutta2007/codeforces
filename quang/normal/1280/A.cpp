#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return 1ll * u * v % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        int sz = s.size();
        for (int i = 0; i < x; i++) {
            int len = sub(sz, i);
            len = sub(len, 1);
            int num = s[i] - '0' - 1;
            int tot = min(x - (int)s.size(), mul(len, num));
            for (int j = 0; j < tot; j++) {
                s += s[s.size() - len];
            }
            sz = add(sz, mul(len, num));
        }
        cout << sz << '\n';
    }
    return 0;
}