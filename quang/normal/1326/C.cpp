#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

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

int n, k;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;   
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long res = 0;
    for (int i = n; i >= n - k + 1; i--) res += i;
    vector<int> ls;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= n - k + 1) ls.push_back(i);
    }
    int num = 1;
    for (int i = 0; i + 1 < ls.size(); i++) {
        num = mul(num, ls[i + 1] - ls[i]);
    }
    cout << res << ' ' << num << endl;
    return 0;
}